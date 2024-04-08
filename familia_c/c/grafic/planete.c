/*
 *  planet.c
 *  Programul arata cum se compun transformarile de rotatie si de translatie
 *  pentru desenarea obiectelor rotite sau translatate.
 *  Interactiune:  left, right, up, down
 *
 */
#include "../include/glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

void myinit(void);
void drawPlane(void);
void CALLBACK dayAdd(void);
void CALLBACK daySubtract(void);
void CALLBACK yearAdd(void);
void CALLBACK yearSubtract(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int year = 0, day = 0;
int rot = 0;
int solRot = 0;
int moonRot = 0;
void CALLBACK dayAdd(void)
{
    day = (day + 10) % 360;
}

void CALLBACK daySubtract(void)
{
    day = (day - 10) % 360;
}

void CALLBACK yearAdd(void)
{
    year = (year + 5) % 360;
}

void CALLBACK yearSubtract(void)
{
    year = (year - 5) % 360;
}
void CALLBACK moonRot0(void)
{
    rot = (rot - 5) % 360;
}
void CALLBACK moonRot1(void)
{
    rot = (rot + 5) % 360;
}
void CALLBACK sunRot0(void)
{
    solRot = (solRot + 5) % 360;
}
void CALLBACK sunRot1(void)
{
    solRot = (solRot - 5) % 360;
}
void CALLBACK moonEarthRot0()//doar in jurul pamantului
{
    moonRot = (moonRot - 5) % 360;
}
void CALLBACK moonEarthRot1()//doar in jurul pamantului
{
    moonRot = (moonRot + 5) % 360;
}
void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();//pentru a nu iesi obiectele din fereastra la reapelarea functiei display()
    glRotatef(30, 1, 1, 1);
    /*  SOARELE    */
    glPushMatrix();
    glRotatef((GLfloat)solRot, 0.0, 1.0, 0.0);
    glPushMatrix();//pt a reorienta polii
    glRotatef(90, 1, 0, 0);
    auxWireSphere(1.0);
    glPopMatrix();
    glPopMatrix();
    /*  Pamantul */
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glPushMatrix();//pt a reorienta polii
    glRotatef(90, 1, 0, 0);
    auxWireSphere(0.2);
    glPopMatrix();
    glPopMatrix();
   

    //Luna//
    glRotatef((GLfloat)moonRot, 0, 1, 0);//de depanat
    glTranslatef(2.4, 0, 0);
    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);
    glPushMatrix();//pt a reorienta polii
    glRotatef(90, 1, 0, 0);
    auxWireSphere(0.1);
    glPopMatrix();
     glPopMatrix();
    
    
    glPopMatrix();
    glFlush();
}

void myinit(void) {
    glShadeModel(GL_FLAT);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}


int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("Composite Modeling Transformations");
    myinit();
    auxKeyFunc(AUX_LEFT, yearSubtract);
    auxKeyFunc(AUX_RIGHT, yearAdd);
    auxKeyFunc(AUX_UP, dayAdd);
    auxKeyFunc(AUX_DOWN, daySubtract);
    auxKeyFunc(AUX_a, moonRot0);
    auxKeyFunc(AUX_d, moonRot1);
    auxKeyFunc(AUX_w, sunRot0);
    auxKeyFunc(AUX_s, sunRot1);
    auxKeyFunc(AUX_o, moonEarthRot0);
    auxKeyFunc(AUX_p, moonEarthRot1);
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
