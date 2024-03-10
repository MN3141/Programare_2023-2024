#include "..\include\openGL_headers.h"
#include "..\include\shapes.cpp"
static GLfloat x = 0;
static GLfloat y = 0;
void CALLBACK reshape(GLsizei w, GLsizei h);
void CALLBACK display(void);
void setup() {
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer-e
    auxInitPosition(0, 0, 500, 500);//setare coordonate fereastra
    auxInitWindow("IPRS");//deschidere fereastra
   // glClearColor(1.0, 0.0, 0.0, 0.0);
    //auxKeyFunc(AUX_LEFT, MutaStanga);
    //auxKeyFunc(AUX_RIGHT, MutaDreapta);
    //auxKeyFunc(AUX_UP, SUS);
    //auxKeyFunc(AUX_DOWN, JOS);
    auxReshapeFunc(reshape);
    auxMainLoop(display);
}

void CALLBACK display(void)//creare scena
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0);
    glPointSize(10);
    glEnd();
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

void CALLBACK reshape(GLsizei w, GLsizei h)//redimensionare fereastra
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

int main(int argc, char** argv)//char **argv e folosit in terminale pt comenzi
{
    setup();
    return(0);
}
