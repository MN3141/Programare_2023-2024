/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "..\include\glos.h"
#include "..\include\openGL_headers.h"
#include<math.h>
float angulus = 0;
float t = 0;
static GLfloat x = 0;
static GLfloat y = 0;
void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK rot_z_up(void)
{
    angulus += 10;
        x+= 10;
}
void CALLBACK rot_z_down(void)
{
    angulus -= 10;
    x -= 10;
}
//circle 
//line
//rectangle
void myinit(void) {
    glClearColor(1.0, 0.0, 0.0, 0.0);
}

void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    auxWireSphere(10);
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

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-320, 320, 320 * (GLfloat)h / (GLfloat)w,
            -160.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-320 * (GLfloat)w / (GLfloat)h,
            320 * (GLfloat)w / (GLfloat)h, -320, 320, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(100, 100, 300,300);
    auxInitWindow("ROTATIE");
    myinit();
    auxReshapeFunc(myReshape);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_down);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    auxMainLoop(display);
    return(0);
}
