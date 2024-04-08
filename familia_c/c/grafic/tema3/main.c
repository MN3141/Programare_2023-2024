#include "../include/glos.h"
#include "../include/openGL_headers.h"
GLfloat angulus0 = 0, angulus1 = 0, angulus2 = 0;
GLfloat angle_step = 10;
void CALLBACK latura00(void)
{
    angulus0 += angle_step;
}
void CALLBACK latura01(void)
{
    angulus0 -= angle_step;
}
void CALLBACK latura10(void)
{
    angulus1 += angle_step;
}
void CALLBACK latura11(void)
{
    angulus1 -= angle_step;
}
void CALLBACK latura20(void)
{
    angulus2 += angle_step;
}
void CALLBACK latura21(void)
{
    angulus2 -= angle_step;
}
void triangle()
{
    glVertex3f(2, 1, 1);
    glVertex3f(4, 3, 3);
    glVertex3f(1, 4, 2);
}
void CALLBACK display(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3ub(0, 0, 255);
    //==============================
    glTranslatef(2, 1, 1);
    glRotatef(angulus0, 2, 2, 2);
    glTranslatef(-2, -1, -1);
    //==============================
    glTranslatef(2, 1, 1);
    glRotatef(angulus1, -1,3,1);
    glTranslatef(-2, -1, -1);
     //==============================
    glTranslatef(4, 3, 3);
    glRotatef(angulus2, -3, 1, -1);
    glTranslatef(-4, -3, -3);
     //==============================
    glBegin(GL_LINE_LOOP);
    triangle();
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
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w,
            10.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-10.0 * (GLfloat)w / (GLfloat)h,
            10.0 * (GLfloat)w / (GLfloat)h, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 1000, 1000);
    auxInitWindow("Rotatii");
    glClearColor(1.0, 0.0, 0.0, 0.0);
    auxKeyFunc(AUX_w, latura00);
    auxKeyFunc(AUX_s, latura01);
    auxKeyFunc(AUX_a, latura10);
    auxKeyFunc(AUX_d, latura11);
    auxKeyFunc(AUX_o, latura20);
    auxKeyFunc(AUX_p, latura21);
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
