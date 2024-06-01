#include "../include/glos.h"
#include "../include/openGl_headers.h"
void curves_init()
{
	glEnable(GL_MAP1_VERTEX_3);	//se valideaza un anumit tip de evaluare
	glEnable(GL_MAP2_VERTEX_3);  // validarea tipului de evaluare GL_MAP2_VERTEX_3
}
void draw_sine_bezier()
{
    /*
       glMap1f() face o m
       glBegin(line-strip)
       for()
           glEvalCoord1f(); deseneaza punctele
       glEnd()
   */

   /*  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
   functia defineste caracteristicile curbei:
   -tipul punctelor de control date in vectorul ctrlpoints, si al
   datelor de iesire generate de functia de evaluare glEvalCoord1f
   -valorile extreme luate de parametrul u (0 si 1 in acst caz)
   -numarul coordonatelor date pentru fiecare punct de control, in tabloul
   ctrlpoints
   -numarul punctelor de control pe baza carora se va determina ordinul curbei
   (numar puncte-1)
   -vectorul punctelor de control
      */


      /* Curba e de tip Bezier !*/
    GLfloat ctrl_points[][3] = {
        {0,0,0},
        {1,3,0},
        {2,0.0},
        {3,-3,0},
        {4,0,0}
    };
    const int NUM_DIVISIONS = 10;
    const int NUM_POINTS = sizeof ctrl_points / (sizeof ctrl_points[0]);
    const int POINT_DIMENSION = sizeof ctrl_points[0] / (sizeof ctrl_points[0][0]);

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, POINT_DIMENSION, NUM_POINTS, &ctrl_points[0][0]);
    glColor3ub(0, 255, 0);

    glBegin(GL_LINE_STRIP);
    for (float i = 0; i <= NUM_DIVISIONS; i++)
        glEvalCoord1f((GLfloat)i / NUM_DIVISIONS);
    glEnd();

    glColor3ub(255, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int i = 0;i < NUM_POINTS;i++)
        glVertex3f(ctrl_points[i][0], ctrl_points[i][1], ctrl_points[i][2]);
    glEnd();

}
void draw_sine_spline(GLUnurbsObj* theNurb)
{
    /* GLfloat ctlpoints[4][3] = {{-.75, -.75, 0.0},
    {-.5, .75, 0.0}, {.5, .75, 0.0}, {.75, -.75, 0.0} };
    */
    GLfloat ctr_points[7][3] = {
        {-2,0,0},
        {-1 ,3,0},
        {0,0,0},
        {1,-3,0},
        {2,0,0},
        {3,3,0},
        {4,0,0}
    };
    //const float POINT_NUM = sizeof ctr_points / (sizeof ctr_points[0]);
    //const float POINT_DIMENSION = sizeof ctr_points[0] / (sizeof ctr_points[0][0]);

    // 8 noduri

    GLfloat knots[10] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 2.0, 2.0 ,2,2 };
    // GLfloat knots[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    glColor3f(1.0, 1.0, 1.0); // culoarea curenta de desenare
    // incepe corpul de redare al curbei Spline
    gluBeginCurve(theNurb);
    gluNurbsCurve(theNurb,	// pointer obiect NURBS
        10, knots,			//numar noduri, tablou noduri
        3,					// intervalul de valori dintre doua puncte de control consecutive
        &ctr_points[0][0],	// vector puncte de control
        4,					// ordinul curbei 
        GL_MAP1_VERTEX_3);	// tip evaluator
    gluEndCurve(theNurb);
}
void draw_surface_wire()
{
    GLfloat ctrlpoints[4][4][3] = {
    {{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0},
    {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}},
    {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0},
    {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}},
    {{-1.5, 0.5, 4.0}, {-0.5, 0.5, 0.0},
    {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}},
    {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0},
    {0.5, 1.5, 0.0}, {1.5, 1.5, -1.0}}
    };

    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); // intervalele de esantionare
    glColor3ub(0, 0, 255);
    glPushMatrix(); // pentru a nu aplica transformari geometrice
    // la fiecare redesenare a ferestrei
    //glRotatef(85, 1.0, 1.0, 1.0);
    //OBS:daca nu am roti obiectul,el s-ar vedea drept un patrat
    glRotatef(45, 0, 1, 0);
    for (int j = 0; j <= 8; j++) {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= 30; i++)
            glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0); // evalueaza un punct
        // pe suprafata pentru valorile u si v ale ale parametrilor
        glEnd();
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= 30; i++)
            glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);
        glEnd();
    }
    glPopMatrix();
}