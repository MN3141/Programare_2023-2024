
/*  curbe_Bezier.c
 *
 Programul utilizeaza evaluatorii pentru determinarea
 punctelor de pe curba Bezier
 */
#include "../include/glos.h"
#include "../include/openGl_headers.h"
#include <stdio.h>

void myinit(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);

GLfloat ctrlpoints[4][3] = {
    //sunt date coordonatele celor 4 puncte de control
    { -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
    {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0} };
GLfloat ctrlPoints0[4][3] = {
    {-2,-4,0},{-3,-4,0},{-4,2,0},{2,2,0}
};
GLfloat ctrlPoints1[5][3] = {
    {2,2,0},{3,2,0},{3,4,0},{4,3.5,0},{4.5,2,0}
};
void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //culoarea background-ului
    //  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
      /*functia defineste caracteristicile curbei:
      -tipul punctelor de control date in vectorul ctrlpoints, si al
      datelor de iesire generate de functia de evaluare glEvalCoord1f
      -valorile extreme luate de parametrul u (0 si 1 in acst caz)
      -numarul coordonatelor date pentru fiecare punct de control, in tabloul
      ctrlpoints
      -numarul punctelor de control pe baza carora se va determina ordinul curbei
      (numar puncte-1)
      -vectorul punctelor de control
         */

    glEnable(GL_MAP1_VERTEX_3);	//se valideaza un anumit tip de evaluare
   // glShadeModel(GL_FLAT); 	//umbrire constanta pe poligoane
    glLineStipple(1, 0x0F0F); //pune liniile punctate
}
void drawCurve0()
{
    
   
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0, 0, 255);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints0[0][0]);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0); //se iau valori pe intervalul [0,1]
    glEnd();
    //curba interpolata
    glColor3ub(255, 0, 0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++)
        glVertex3fv(&ctrlPoints0[i][0]);
    glEnd();
    //puncte control
    glEnable(GL_LINE_STIPPLE); //linii intrerupte
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 4; i++)
        glVertex3fv(&ctrlPoints0[i][0]);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void drawCurve1()
{
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0, 0, 255);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints1[0][0]);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);
    glEnd();
    //curba interpolata
    glColor3ub(255, 0, 0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 5; i++)
        glVertex3fv(&ctrlPoints1[i][0]);
    glEnd();
    //puncte control
    glEnable(GL_LINE_STIPPLE);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 5; i++)
        glVertex3fv(&ctrlPoints1[i][0]);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void draw_test_curve()
{
    /*
       glMap1f() face o m
       glBegin(line-strip)
       for()
           glEvalCoord1f(); deseneaza punctele
       glEnd()
   */
    GLfloat ctrl_points[][3] = {
        {0,0,0},
        {2,-1,0},
        {3,1,0},
        {4,0,0},
        {4,1,0}
    };
    const float NUM_DIVISIONS = 10;

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrl_points[0][0]);
    glColor3ub(0, 255, 0);

    glBegin(GL_LINE_STRIP);
    for (float i = 0; i <= NUM_DIVISIONS; i++)
        glEvalCoord1f(i/NUM_DIVISIONS);
    glEnd();

    glColor3ub(255, 0, 0);
    printf("Num points: %d\n", sizeof(ctrl_points[0])/sizeof(GLfloat));
   // glBegin(GL_POINTS);
   
}
void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawCurve0();
    //drawCurve1();
    draw_test_curve();
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
    return(0);
}
