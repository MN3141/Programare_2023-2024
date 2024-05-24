#include<stdio.h>
#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include "draw.h"

#define ANIMATION_STEP 10
#define ANIMATION_THRESSHOLD0 90
#define ANIMATION_THRESSHOLD1 -15

int debug_angle = 0;
float animation_angle = 0;
float camera_z = 0;
float camera_x = 0;
const float CAMERA_STEP = 1.5;

void CALLBACK debug_rot0()
{
    debug_angle = (debug_angle + 1) % 361;
    printf("Rot0: %d\n", debug_angle);
}
void CALLBACK debug_rot1()
{
    debug_angle =(debug_angle - 1) % 361;
    printf("Rot1: %d\n", debug_angle);
}
void CALLBACK wave0()
{
    if (animation_angle < ANIMATION_THRESSHOLD0)
        animation_angle += ANIMATION_STEP;
}
void CALLBACK wave1()
{
    if (animation_angle>-ANIMATION_THRESSHOLD1)
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
void CALLBACK camera_forward()
{
    camera_z += CAMERA_STEP;
    printf("Camera z: %f \n", camera_z);
}
void CALLBACK camera_backwards()
{
    camera_z -= CAMERA_STEP;
    printf("Camera z: %f\n", camera_z);
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
    glClearColor(0.4,0.435,0.843,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    float snow_ambient[] = {0.5,0.5,0.5,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, snow_ambient);
    glMaterialf(GL_FRONT, GL_SHININESS, 70);

    gluLookAt(camera_x, 0, 400+camera_z, 0, 0, 0, 0, 1, 0);
    glRotatef(debug_angle,1,0,0); 
    draw_snow_man(animation_angle);
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
    auxInitWindow("Om zapada");

    light_init();

    auxKeyFunc(AUX_LEFT, camera_left);
    auxKeyFunc(AUX_RIGHT, camera_right);
    auxKeyFunc(AUX_UP, camera_forward);
    auxKeyFunc(AUX_DOWN, camera_backwards);
    auxKeyFunc(AUX_o, debug_rot0);
    auxKeyFunc(AUX_p, debug_rot1);
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
