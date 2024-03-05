#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>//toate functiile si constantele cu aux sunt din GLAUX.H
#include<math.h>
static GLfloat x = 0;
static GLfloat y = 0;
void CALLBACK reshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
void setup() {
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer-e
    auxInitPosition(0, 0, 500, 500);//setare coordonate fereastra
    auxInitWindow("IPRS");//deschidere fereastra
   // glClearColor(1.0, 0.0, 0.0, 0.0);
    //auxKeyFunc(AUX_LEFT, MutaStanga);
    //auxKeyFunc(AUX_RIGHT, MutaDreapta);
    //auxKeyFunc(AUX_UP, SUS);
    //auxKeyFunc(AUX_DOWN, JOS);
    auxReshapeFunc(reshape);
    auxMainLoop(display);
}
void line() {
    glPointSize(5);
    glBegin(GL_POINTS);
    for (float i = 0; i < 100; i+=0.1)
    {
        glColor3ub(0, 0, 255);//OBS:glColor3b() lucreaza cu octeti cu semn!
        glVertex2d(i, i);
    }
    glEnd();
}
void quadratic() {
    glPointSize(5);
    glBegin(GL_LINE_LOOP);
    for (float i = 0; i <= 100; i=i+0.1) {
        glColor3ub(255, 0, 0);
        glVertex2d(i, i*i);
        }
    glEnd();
}
void circleFill()
{
    glPointSize(2);
    glBegin(GL_POLYGON);
        for (float i = 0; i < 2 * 3.141; i = i + 0.1)
        {
            glColor3ub(0, 255, 0);
            glVertex2d(100 * cos(i), 100 * sin(i));
        }
    glEnd();
}
void circleEmpty()
{
    glPointSize(2);
    glBegin(GL_LINE_LOOP);
    for (float i = 0; i < 2 * 3.141; i = i + 0.1)
    {
        glColor3ub(0, 255, 0);
        glVertex2d(100 * cos(i), 100 * sin(i));
    }
    glEnd();
}
void sineCurve()
{
    glPointSize(2);
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t < 100; t += 0.1)
        {
        glColor3ub(0, 0, 255);
        glVertex2d(t, 10*sin(t));
        }
    glEnd();
}
void house()
{
    glPointSize(2);
    glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        glVertex2d(50, 0);
        glColor3ub(0, 0, 255);
        glVertex2d(50, 50);
        glColor3ub(0, 0, 255);
        glVertex2d(0, 50);
        glColor3ub(0, 0, 255);
        glVertex2d(0, 0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 0, 255);
        glVertex2d(0, 50);
        glColor3ub(0, 0, 255);
        glVertex2d(50, 50);
        glColor3ub(0, 0, 255);
        glVertex2d(25, 75);
    glEnd();
}
void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0);
    //line();
    //quadratic();
    //circleFill();
    //circleEmpty();
    //sineCurve();
    house();
    glFlush();
}

/*void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;			//transformare anizotropica, forma se modifica functie de forma(dimens) viewportului
    glViewport(0, 0, w, h);	//daca w>h stabilim ca baza inaltime, si stab unit logica de dimens in fct de h(h/320, 320 lungime lat patrat)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-160.0, 160.0, -160.0,
        160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}*/

void CALLBACK reshape(GLsizei w, GLsizei h)//redimensionare fereastra
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-160.0, 160.0, 160.0 * (GLfloat)h / (GLfloat)w,
            -160.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-160.0 * (GLfloat)w / (GLfloat)h,
            160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    setup();
    return(0);
}
