#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<stdio.h>
const float pi = 3.14159;
static GLfloat x = 0;
static GLfloat y = 0;
float length = 400;
GLfloat angulus = 0;
GLUquadric* obj = NULL;
void CALLBACK MutaStanga(void)
{
    x = x - 600;
    printf("\n %s %f", "X:", x);
}
void CALLBACK MutaDreapta(void)
{
    x = x + 600;
    printf("\n %s %f", "X:", x);
}
void CALLBACK SUS(void)
{
    y = y + 600;
    printf("\n %s %f", "Y:", y);
}
void CALLBACK JOS(void)
{
    y = y - 600;
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
void frame()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
        for (float i = -length/2; i <= length/2; i+=length/6)//liniile verticale 
        {
            glVertex2f(i, length);
            glVertex2f(i, -length);
        }
        for (float i = length; i >= -length; i -= 2*length /3)//liniile orizontale 
         {
             glVertex2f(-length / 2, i);
             glVertex2f(length / 2, i);
         }
    glEnd();
}
void axes()
{
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-length/2,0);
    glVertex2f(length / 2, 0);
    glVertex2f(0, length);
    glVertex2f(0, -length);
       glEnd();
}
void cylinder()
{
    glPushMatrix();
    glColor3ub(0, 247, 255);
    float temp = -length / 2;
    ///TRANSLATIE,apoi ROTATIE!
    glTranslatef((2*temp+length/6)/2, length-2*length/6,0);
    glRotatef(-240, 1, 0, 0);
    glRotatef(60, 0, 1, 1);
    gluCylinder(obj, 40, 40,50,20,1);
    glPopMatrix();
}
void prism6()
{
    glPushMatrix();
    glColor3ub(0, 26, 255);
    float temp = -length/2+length/6;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-120, 1, 0, 0);
    glRotatef(90, 0, 1, 1);
    gluCylinder(obj, length/20, length/20, length/10+20, 6, 1);
    glPopMatrix();
}
void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    frame();
    //DE AJUSTAT DIMENSIUNEA CORPURILOR IN FUNCTIE DE length
    cylinder();
    prism6();
    glFlush();
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
void init()
{
    obj = gluNewQuadric();
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer
    auxInitPosition(00, 00, 1000, 1000);//setare coordonate fereastra
    auxInitWindow("Tema 1");
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
