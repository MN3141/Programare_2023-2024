
#include "../include/glos.h"
#include "../include/openGl_headers.h"
#include "curves.h"
#include <stdio.h>

void myinit(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
GLUnurbsObj* theNurb;

void myinit(void)
{
    curves_init();
   // glShadeModel(GL_FLAT); 	//umbrire constanta pe poligoane
    glLineStipple(1, 0x0F0F); //pune liniile punctate

    theNurb = gluNewNurbsRenderer();
    //NURB = Non Uniform Rational B Spline
    // este creat dinamic in memoria libera prin apelul functiei gluNewNurbsRenderer()
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 10.0);
    // eroarea de esantionare a curbei la redare
}
void CALLBACK display(void)
{
    glClearColor(0, 0, 0, 0);
    //draw_sine_spline(theNurb);
    //draw_sine_bezier();
    draw_surface_wire();
    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
            5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
    else
        glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
            5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("Test curbe");
    myinit();
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    gluDeleteNurbsRenderer(theNurb);
    return(0);
}
