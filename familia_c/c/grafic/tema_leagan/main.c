#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<stdio.h>
//OpenGL=automat cu stari finite
const float pi = 3.14159;
GLfloat yAngulus = 0;
GLfloat xAngulus = 0;
GLUquadric* obj = NULL;
GLUquadric* obj2 = NULL;
void CALLBACK reset()
{
    yAngulus = xAngulus = 0;
}
void CALLBACK rotPlus()
{
    yAngulus += 10;
}
void CALLBACK rotMin()
{
    yAngulus -= 10;
}
void CALLBACK rotUp()
{
    xAngulus += 10;
}
void CALLBACK rotDown()
{
    xAngulus -= 10;
}
void drawBase(float pos[])
{
    float baseRadius = 100;
    float baseHeight = 100;
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(pos[0], pos[1], pos[2]);
    
    gluCylinder(obj, baseRadius, baseRadius, baseHeight, 4, 4);
    glPopMatrix();
}
void drawCylinder(float pos[])
{
    float cylinderRadius = 10;
    float cylinderHeight = 300;
    glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);
    gluCylinder(obj2, cylinderRadius, cylinderRadius, cylinderHeight, 20, 1);
    glPopMatrix();
}
void CALLBACK draw(void)//creare scena
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLfloat low_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, low_ambient);
    glMaterialf(GL_FRONT, GL_SHININESS, 40.0);
    glRotatef(yAngulus, 0, 1, 0);
    //==================================
    //Rotatie
    glTranslatef(0,255,0);//implicit axa de rotatie trece prin origine
    glRotatef(xAngulus, 1, 0, 0);
    glTranslatef(0, -255, 0);
    //=================================
    //Baza
    glPushMatrix();
    float pos0[] = { 0,0,0 };
    glColor3ub(0, 0, 255);
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    drawBase(pos0);
    glPopMatrix();
    //=================================
    glPushMatrix();
    float pos1[] = { -30,50,0 };
    glColor3ub(255, 0, 0);
    glRotatef(-90, 1, 0, 0);
    drawCylinder(pos1);
    glPopMatrix();
    //=================================
    glPushMatrix();
    float pos2[] = { 30,50,0 };
    glColor3ub(0, 255, 0);
    glRotatef(-90, 1, 0, 0);
    drawCylinder(pos2);
    glPopMatrix();
    //=================================
    glPushMatrix();
    float pos3[] = {50,310,-150 };
    glColor3ub(255, 255, 0);
    glRotatef(90, 0, 1, 0);
    drawCylinder(pos3);
    glPopMatrix();
    //=================================
    glPopMatrix();
    glFlush();//important,deoarece goleste buffer-ul
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-300, 300, -1000 * (GLfloat)h / (GLfloat)w,//pentru dimensiuni logice
            1000 * (GLfloat)h / (GLfloat)w, -1000, 1000);
    else
        glOrtho(-300 * (GLfloat)w / (GLfloat)h,
            300 * (GLfloat)w / (GLfloat)h, -1000, 1000, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
}
void init_light()
{
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat global_ambient[] = { 0.75, 0.75, 0.75, 1.0 };
    //format:R G B alpha
    GLfloat light_position[] = { 1.0, 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    //fv=float vertex/pointer tablou
    glFrontFace(GL_CW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

}
void init()
{
    init_light();
    obj = gluNewQuadric();
    obj2 = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_SMOOTH);
    gluQuadricDrawStyle(obj2, GLU_SMOOTH);
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH16);//setare buffer
    auxInitPosition(00, 00, 1000, 1000);//setare coordonate fereastra
    auxInitWindow("Leagan");
    auxKeyFunc(AUX_LEFT, rotPlus);
    auxKeyFunc(AUX_RIGHT, rotMin);
    auxReshapeFunc(myReshape);
    auxKeyFunc(AUX_UP, rotUp);
    auxKeyFunc(AUX_DOWN, rotDown);
    auxKeyFunc(AUX_r, reset);
    auxMainLoop(draw);
}
int main(int argc, char** argv)
{
    init();
    gluDeleteQuadric(obj);
    gluDeleteQuadric(obj2);
    return(0);
}
