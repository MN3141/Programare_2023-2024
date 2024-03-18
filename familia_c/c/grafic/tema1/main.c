#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<stdio.h>
const float pi = 3.14159;
static GLfloat x = 0;
static GLfloat y = 0;
float length = 300;
GLfloat angulus = 0;
GLUquadric* obj = NULL;
GLUquadric* obj2 = NULL;
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
    //pt depanare si orientare
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
    float radius = length / 12-20 ; //2*radius<=length/6
    ///TRANSLATIE,apoi ROTATIE!
    glTranslatef((2*temp+length/6)/2, length-2*length/6,0);
    glRotatef(-240, 1, 0, 0);
    gluCylinder(obj, radius, radius, length/6,20,1);
    glPopMatrix();
}
void prism6()
{
    glPushMatrix();
    glColor3ub(0, 26, 255);
    float temp = -length/2+length/6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius,radius,length/6, 6, 1);
    glPopMatrix();
}
void prism5()
{
    glPushMatrix();
    glColor3ub(51, 255, 0);
    float temp = -length / 2 + 2*length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius, radius, length / 6, 5, 1);
    glPopMatrix();
}
void prism3()
{
    glPushMatrix();
    glColor3ub(245, 8, 221);
    float temp = -length / 2 + 3 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius, radius, length / 6, 3, 1);
    glPopMatrix();
}
void cone()
{
    glPushMatrix();
    glColor3ub(154, 27, 27);
    float temp = -length / 2 + 4 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius, 0, length / 6, 20, 1);
    glPopMatrix();

}
void coneTrunk()
{
    glPushMatrix();
    glColor3ub(91, 189, 35);
    float temp = -length / 2 + 5 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, length - 2 * length / 6, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius, radius/2, length / 6, 20, 1);
    glPopMatrix();
}
void squarePyramid()
{
    glPushMatrix();
    glColor3ub(154, 27, 27);
    float temp = -length / 2;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, 0, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(14.13, 0, 0, 1);
    gluCylinder(obj, radius, 0, length / 6, 4, 1);
    glPopMatrix();
}
void trigPyramid()
{
    glPushMatrix();
    glColor3ub(0, 25, 51);
    float temp = -length / 2+length/6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, 0, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(40, 0, 0, 1);
    gluCylinder(obj, radius, 0, length / 6, 3, 1);
    glPopMatrix();
}
void hexPyramid() {
    glPushMatrix();
    glColor3ub(0, 102, 0);
    float temp = -length / 2 + 2*length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2 +x, 0+y, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(7.10, 0, 0, 1);
    gluCylinder(obj, radius, 0, length / 6, 6, 1);
    glPopMatrix();
}
void pentaPyramid() {
    glPushMatrix();
    glColor3ub(0, 102, 102);
    float temp = -length / 2 + 3 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, 0, 0);
    glRotatef(-230, 1, 0, 0);
    glRotatef(20, 0, 0, 1);
    gluCylinder(obj, radius, 0, length / 6, 5, 1);
    glPopMatrix();
}
void diskCircle()
{
    glPushMatrix();
    glColor3ub(153, 76, 102);
    float temp = -length / 2 + 4 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, 0, 0);
    glRotatef(angulus, 0, 0, 28.274296);
    gluDisk(obj, 0, radius, 20, 1);
    glPopMatrix();
}
void diskHexagon() {
    glPushMatrix();
    glColor3ub(0, 0, 255);
    float temp = -length / 2 + 5 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, 0, 0);
    glRotatef(28.274296, 0, 0, 1);
    gluDisk(obj, 0, radius, 6, 1);
    glPopMatrix();
}
void diskTriangle()
{
    glPushMatrix();
    glColor3ub(0, 153, 0);
    float temp = -length / 2 ;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2*length/3, 0);
    glRotatef(28.274296, 0, 0, 1);
    gluDisk(obj, 0, radius, 3, 1);
    glPopMatrix();
}
void Sphere()
{

    glPushMatrix();
    glColor3ub(22, 116, 119);
    float temp = -length / 2+length/6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2 * length / 3, 0);
    glRotatef(angulus, 1, 0, 0);
    gluSphere(obj, radius, 15, 15);
    glPopMatrix();
}
void Polyhedron4()
{
    glPushMatrix();
    glColor3ub(200, 8, 119);
    float temp = -length / 2 + 2*length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2 * length / 3, 0);
    glRotatef(28.274296, 1, 0, 0);//28.274296
    gluCylinder(obj, radius, radius, length / 6, 4, 4);
    glPopMatrix();
}
void Polyhedron6()
{
    glPushMatrix();
    glColor3ub(22, 7, 2);
    float temp = -length / 2 + 3* length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2 * length / 3, 0);
    glRotatef(10, 0,1, 0);
    gluCylinder(obj, radius, radius, length / 6, 6, 6);
    glPopMatrix();
}
void Polyhedron8()
{
    glPushMatrix();
    glColor3ub(22, 0, 119);
    float temp = -length / 2 + 4 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2 * length / 3, 0);
    glRotatef(5, 0, 1, 0);
    gluCylinder(obj, radius, radius, length / 6, 8, 8);
    glPopMatrix();
}
void cakeSLice()
{
    glPushMatrix();
    glColor3ub(43, 29, 20);
    float temp = -length / 2 + 5 * length / 6;
    float radius = length / 12 - 20;
    glTranslatef((2 * temp + length / 6) / 2, -2 * length / 3, 0);
    glRotatef(-230, 1, 0, 0);
    gluCylinder(obj2, radius, radius, length / 6, 3, 1);
    glColor3ub(255, 255, 0);
    gluDisk(obj2, 0, radius, 3, 1);
    glPopMatrix();
}
void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    frame();
    cylinder();
    prism6();
    prism5();
    prism3();
    cone();
    coneTrunk();
    squarePyramid();
    trigPyramid();
    hexPyramid();
    pentaPyramid();
    diskCircle();
    diskHexagon();
    diskTriangle();
    Sphere();
    Polyhedron4();
    Polyhedron6();
    Polyhedron8();
    cakeSLice();
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
    obj2 = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_SILHOUETTE);
    gluQuadricDrawStyle(obj2, GLU_FILL);
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
    gluDeleteQuadric(obj);
    gluDeleteQuadric(obj2);
    return(0);
}
