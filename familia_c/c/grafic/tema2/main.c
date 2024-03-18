/*  curbe_Bezier.c
 *
 Programul utilizeaza evaluatorii pentru determinarea
 punctelor de pe curba Bezier
 */
#include "../include/glos.h"
#include "../include/openGl_headers.h"
void myinit(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);

GLUnurbsObj* theNurb; // curba este un obiect de tipul GLUnurbsObj

void myinit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	// glEnable(GL_DEPTH_TEST);
	theNurb = gluNewNurbsRenderer(); // obiectul de tip GLUnurbsObj
	// este creat dinamic in memoria libera prin apelul functiei gluNewNurbsRenderer()
	gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 10.0);
	// er0area de esantionare a curbei la redare
	glLineStipple(1, 0x0F0F);
	glPointSize(5);
}
void CALLBACK display(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	int i;
	GLfloat ctlpoints[10][3] = {
		{-2,-0.5,0},
		{0.5,4,0},
		{0.45,6,0},
		{-1,4.2,0},
		{0.35,-2,0},
		{2.5,0.85,0},
		{2.7,3.2,0},
		{-0.2,2,0},
		{1.5,-0.25,0},
		{4,2.8,0},
	};

	GLfloat knots[14] = { 0,0,0,0,1,2,3,4,5,6,7,7,7,7 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(0, 0, 255);; // culoarea curenta de desenare

	glLoadIdentity();
	glTranslated(0.2, 0.0, -1.0);
	glScaled(0.2, 0.2, 0.2);


	// incepe corpul de redare al curbei Spline
	glDisable(GL_LINE_STIPPLE);
	gluBeginCurve(theNurb);
	gluNurbsCurve(theNurb,	// pointer obiect NURBS
		14, knots,			//numar noduri, tablou noduri
		3,					// intervalul de valori dintre doua puncte de control consecutive
		&ctlpoints[0][0],	// vector puncte de control
		4,					// ordinul curbei 
		GL_MAP1_VERTEX_3);	// tip evaluator
	gluEndCurve(theNurb);

	// punctele de control
	glColor3ub(255, 0, 255);
	glBegin(GL_POINTS);

	// punctele de control
	for (i = 0; i < 10; i++)
		glVertex3fv(&ctlpoints[i][0]);
	glEnd();

	//poligonul caracteristic
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 10; i++)
		glVertex3fv(&ctlpoints[i][0]);
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
		gluOrtho2D(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
			1.5 * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-1.5 * (GLfloat)w / (GLfloat)h,
			1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*  Main Loop
 */
int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 500, 500);
	auxInitWindow("Litera b");
	myinit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
