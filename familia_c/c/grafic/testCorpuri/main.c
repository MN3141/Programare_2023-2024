#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<stdio.h>
#include<math.h>
#include<stdio.h>
float pi = 3.141592;
int radius = 100;
float angulus = 0;
GLUquadric* obj=NULL;
void CALLBACK rot(void)
{
    angulus += 30;
    printf("\n%f", angulus);
}
void cylinder()
{
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glRotated(-240, 1, 0, 0);//rotatia se face in sens trigonometric
    glRotatef(angulus, 1, 0, 0);
    glBegin(GL_QUAD_STRIP);
        for (float i = 0; i <= 2 * pi; i += 0.1)   
        {
            glVertex3f(radius * cos(i), 100, radius * sin(i));
            glVertex3f(radius * cos(i), -100, radius * sin(i));
        }
    glEnd();
    glPopMatrix();
}
void cylinder2()
{
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslated(100, 100, 0);
    glRotated(90, 0, 1, 1);
    gluCylinder(obj, 100, 100, 100, 10, 1);
    glPopMatrix();
}
void prism0()
{
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslatef(400, 400, 0);
    glRotatef(90, 1,1, 1);
    glBegin(GL_QUAD_STRIP);
    glLineWidth(10);
    for (float i = 0; i <= 20; i += pi/3)
    {
        glVertex3f(radius * cos(i), 100, radius * sin(i));
        glVertex3f(radius * cos(i), -100, radius * sin(i));
    }
    glEnd();
    glPopMatrix();
}
void prism1()
{
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glTranslatef(-500, 100, 0);
   // glRotatef(90, 1, 1, 1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.0f, 0.0f); 
    glVertex2d(100, 0);
    glVertex2d(50, 50);
    glVertex2d(150, 50);
    glVertex2d(100,100);
    glEnd();
    glPopMatrix();
}
void sphere()
{
    glPushMatrix();
    glColor3ub(0, 255, 255);
    glTranslatef(100, 400, 200);
    glRotated(60, 1, 1, 1);
    auxWireSphere(100);
    glPopMatrix();

}
void cone()
{
    glPushMatrix();
    glColor3ub(40, 31, 31);
    glRotated(angulus, 0, 0, 1);
    gluCylinder(obj, 100, 0, 400, 20, 1);
    glPushMatrix();
}
void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    prism0();
    glFlush();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1000.0, 1000.0, 1000.0 * (GLfloat)h / (GLfloat)w,//pentru proiectie oblica si coordonate logice
            -1000.0 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
    else
        glOrtho(-1000.0 * (GLfloat)w / (GLfloat)h,
            1000.0 * (GLfloat)w / (GLfloat)h, -1000.0, 1000.0, -1000.0, 1000.0);//znear si zfar
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    obj = gluNewQuadric();
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer
    auxInitPosition(0, 0, 1000, 1000);//setare coordonate fereastra
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot);
    auxInitWindow("Test corpuri");
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
}
int main(int argc, char** argv)
{
    init();
    return(0);
}
