#include<stdio.h>
#include "draw.h"
#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#define ANIMATION_STEP 10
#define ANIMATION_THRESSHOLD0 90
#define ANIMATION_THRESSHOLD1 -15

int light_offset = 0;
float animation_angle = 0;
float camera_y = 0;
float camera_x = 0;
const float CAMERA_STEP = 0.05;
void CALLBACK reset()
{
    camera_x = 0;
    camera_y = 0;
    light_offset = 0;
}
void CALLBACK light_move0()
{
    light_offset =light_offset + 10;
    printf("Light0: %d\n", light_offset);
}
void CALLBACK light_move1()
{
    light_offset = light_offset - 10;
    printf("Light1: %d\n", light_offset);
}
void CALLBACK wave0()
{
    if (animation_angle < ANIMATION_THRESSHOLD0)
        animation_angle += ANIMATION_STEP;
}
void CALLBACK wave1()
{
    if (animation_angle > -ANIMATION_THRESSHOLD1)
        animation_angle -= ANIMATION_STEP;
    printf("Wave-: %f\n", animation_angle);
}
/*void CALLBACK wave_animation()
{
    if(animation_angle>=0 && animation_angle<=ANIMATION_THRESSHOLD0)
        animation_angle += ANIMATION_STEP;
    else if(animation_angle>=ANIMATION_THRESSHOLD1 && animation_angle<=0)
        animation_angle -= ANIMATION_STEP;
    printf("DA\n");
    draw_scene();
    Sleep(300);
}*/
void CALLBACK camera_up()
{
    camera_y -= CAMERA_STEP;
    printf("Camera y: %f \n", camera_y);
}
void CALLBACK camera_down()
{
    camera_y += CAMERA_STEP;
    printf("Camera y: %f\n", camera_y);
}
void CALLBACK camera_left()
{
    camera_x -= CAMERA_STEP;
    printf("Camera x: %f\n", camera_x);
}
void CALLBACK camera_right()
{
    camera_x += CAMERA_STEP;
    printf("Camera x: %f\n", camera_x);
}
void CALLBACK draw_scene(void)
{
    //   glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearColor(0.4, 0.435, 0.843, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity(); //resetare matrice vizualizare

    float snow_ambient[] = { 0.5,0.5,0.5,1 };
    float light_pos2[] = { 0,200+light_offset,100,0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, snow_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos2);
    //glMaterialf(GL_FRONT, GL_SHININESS, 10);

    // oricare trei puncte din plan
    float plane_points[3][3] = {
        {500,-110,-500},
        {500,-110,500},
        {250,-110,500}
    };//in ordine trigonometrica
    float matrix_shadow[4][4];
    MatriceUmbra(plane_points, matrix_shadow);//determinã matricea pentru calcularea umbrei	

    gluLookAt(0, 0,1, camera_x, camera_y, 0, 0, 1, 0);//modifica matricea de vizualizare
    //glRotatef(light_offset, 0, 1,0);
    glTranslatef(0, 0, -400);//deplasare obiect departe de utilizator

    glRotatef(20, 1, 0, 0);//rotire pe axa OX pt a vizualiza planul
    glPushMatrix();
    draw_plane();
    draw_snow_man(animation_angle);
    glPopMatrix();//salveaza starea matricei de modelare-vizualizare
    glPushAttrib(GL_LIGHTING_BIT);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    //apoi se înmulteste matricea curentã cu matricea de umbrire
    glMultMatrixf((GLfloat*)matrix_shadow);
    glColor3f(0.4, 0.4, 0.4);
    draw_snow_man(animation_angle);
    glPopMatrix();

    glPopAttrib();//restaureazã starea variabilelor de iluminare
    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1000, 1000, -1000 * (GLfloat)h / (GLfloat)w,//pentru dimensiuni logice
            1000 * (GLfloat)h / (GLfloat)w, -1000, 1000);
    else
        glOrtho(-300 * (GLfloat)w / (GLfloat)h,
            300 * (GLfloat)w / (GLfloat)h, -1000, 1000, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH16);//setare buffer
    auxInitPosition(00, 00, 1000, 1000);//setare coordonate fereastra
    auxInitWindow("Om de zapada");

    light_init();
    
    glEnable(GL_DEPTH_TEST);
   // glEnable(GL_NORMALIZE); //pt calculul normalelor in cazul corpurilor modelate propriu

    auxKeyFunc(AUX_LEFT, camera_left);
    auxKeyFunc(AUX_RIGHT, camera_right);
    auxKeyFunc(AUX_UP, camera_up);
    auxKeyFunc(AUX_DOWN, camera_down);
    auxKeyFunc(AUX_r, reset);
    auxKeyFunc(AUX_o, light_move0);
    auxKeyFunc(AUX_p, light_move1);
    auxKeyFunc(AUX_a, wave0);
    auxKeyFunc(AUX_d, wave1);
    auxReshapeFunc(myReshape);
    //  auxIdleFunc(wave_animation);
    auxMainLoop(draw_scene);
}
int main(int argc, char** argv)
{
    init();
    return 0;
}
