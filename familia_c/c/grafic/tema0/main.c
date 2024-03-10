#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<stdio.h>
const float pi = 3.14159;
static GLfloat x = 0;
static GLfloat y = 0;
GLfloat angulus = 0;
void CALLBACK MutaStanga(void)
{
    x = x - 10;
    printf("\n %s %f", "X:", x);
}
void CALLBACK MutaDreapta(void)
{
    x = x + 10;
    printf("\n %s %f", "X:", x);
}
void CALLBACK SUS(void)
{
    y = y + 10;
    printf("\n %s %f", "Y:", y);
}
void CALLBACK JOS(void)
{
    y = y - 10;
    printf("\n %s %f", "Y:", y);
}
void CALLBACK leftClick(void) {
    angulus += pi / 4;
    printf("\n %s %f", "Alfa:", angulus);
}
void CALLBACK rightClick(void) {
    angulus -= pi / 4;
    printf("\n %s %f", "Alfa:", angulus);
}

void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(x, y, 0.0);
    glRotatef(angulus, 0, 0, 1);
    glBegin(GL_QUADS);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(100, 100);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(150.0, 100.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(100.0, 150.0);
    glEnd();
    glFlush();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-160.0, 160.0, 160.0 * (GLfloat)h / (GLfloat)w,//pentru proiectie oblica
            -160.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-160.0 * (GLfloat)w / (GLfloat)h,
            160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer
    auxInitPosition(400, 400, 0, 0);//setare coordonate fereastra
    auxInitWindow(L"Tema 0");
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxKeyFunc(AUX_UP, SUS);
    auxKeyFunc(AUX_DOWN, JOS);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, leftClick);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rightClick);
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
}
int main(int argc, char** argv)
{
    init();
    return(0);
}
