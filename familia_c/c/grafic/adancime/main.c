/*
 Eliminarea fetelor functie de orientare
 Se va afisa fara activarea eliminarii fetelor. Cu orientarea
 directa implicita se  vor schimba fetele care se elimina-
 cele fata sau cele spate-cu functia glCullFace.
 Se va schimba apoi ordinea directa a varfurilor cu glFrontFace
 avand parametrii - GL_CW, GL_CCW.
 */
#include "../include/glos.h"
#include "../include/openGL_headers.h"

void myinit(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
float angulus = 0;

void myinit(void)
{

    glClearColor(0.0, 0.0, 0.0, 1.0);

}

void CALLBACK rot()
{
    angulus += 30;
}
void CALLBACK display0(void)
{
    /*to cull ~= a culege
    glEnable(GL_CULL_FACE) -activare ignorare fete
    glCullFace()-selectare tip fata de eliminat
    CCW-sens trigonometric
    CW-sens ceas
    glFrontFace()-specificare explicita ce constituie fata sau spate
    */

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);//activeaza eliminarea fetelor
    glCullFace(GL_BACK);//sunt eliminate fetele spate
    //inlocuiti cu GL_FRONT pentru fete fata
    glRotatef(angulus, 0, 1, 0);
    glBegin(GL_POLYGON);//orientare GL_CCW-implicita ca orientare directa
    glVertex2f(-1.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
    glFrontFace(GL_CW);
    /*Sa se modifice sursa astfel încât să permită vizualizarea
        ambelor poligoane chiar dacă se activează tăierea feţelor cu
        funcţia glCullFace().Nu se va modifica modelarea
        dreptunghiurilor.
        */
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//orientare GL_CW-implicita ca orientare indirecta
    glVertex2f(1.0, 1.0);
    glVertex2f(2.0, 1.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    glFlush();
}
void CALLBACK display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //GL_DEPTH_BUFFER_BIT
    glColor3f(1.0, 0.0, 0.0);
    //glEnable(GL_CULL_FACE);//activeaza eliminarea fetelor
   // glCullFace(GL_BACK);//sunt eliminate fetele spate
    glEnable(GL_DEPTH_TEST);//ascunde fetele spate asemenea eliminarii
                            //dar ele pot fi observate in urma rotatilor!
    glRotatef(30, 1.0, 1.0, 0.0);
    /*
    OBS:daca glCullFace() este setat
        la rotatie cubul mereu va avea
        laturi fete lipa
    */
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glFlush();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 3.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -4.0);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 400);
    auxInitWindow("Eliminarea fetelor functie de orientare");
    myinit();
    auxKeyFunc(AUX_LEFT, rot);
    auxReshapeFunc(myReshape);
    auxMainLoop(display1);
    return(0);
}
