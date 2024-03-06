#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>//toate functiile si constantele cu aux sunt din GLAUX.H
#include<math.h>
void line() {
    glPointSize(5);
    glBegin(GL_POINTS);
    for (float i = 0; i < 100; i += 0.1)
    {
        glColor3ub(0, 0, 255);//OBS:glColor3b() lucreaza cu octeti cu semn!
        glVertex2d(i, i);
    }
    glEnd();
}
void quadratic() {
    glPointSize(5);
    glBegin(GL_LINE_LOOP);
    for (float i = 0; i <= 100; i = i + 0.1) {
        glColor3ub(255, 0, 0);
        glVertex2d(i, i * i);
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
        glVertex2d(t, 10 * sin(t));
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