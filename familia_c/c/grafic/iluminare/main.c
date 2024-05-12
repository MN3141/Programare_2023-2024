//OBS:GLUT=Graphics Library Utility Toolkit
//CALLBACK - folosit de GLUT
#include "../include/glos.h"
#include "../include/openGL_headers.h"
void init(void)
{ 
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH16);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("Iluminare");
 
    //setãri pentru sursa de luminã
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };//intensitatea
    //Red Green Blue Alpha intensity
    //componentei ambientale din sursa 0 este nula
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };//intensitatea
    //componentei difuze din sursa 0 este maxima pentru fiecare componenta de
    //culoare
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };//intensitatea
    //componentei speculare din sursa 0 este maxima pentru fiecare componenta de
    //culoare
/*  pozitia sursei de luminã nu este cea implicitã */

    GLfloat light_position[] = { 1.0, 0.0, 0.0, 0.0 };
    //sursa de lumina pe axa x la infinit
    GLfloat global_ambient[] = { 0.75, 0.75, 0.75, 1.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLight float vertex
    //vertex <- pointer tablou

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    //lumina ambientala in scena

    glFrontFace(GL_CW);//orientarea implicit[ a vârfurilor în sensul rotirii acelor
    glEnable(GL_LIGHTING); //activare iluminare
    glEnable(GL_LIGHT0); //activare sursa 0
    glEnable(GL_AUTO_NORMAL); //activare calculare normale daca vârfurile 
    //s-au determinat cu GL_MAP2_VERTEX_3 sau GL_MAP2_VERTEX_4
    glEnable(GL_NORMALIZE); //activare normalizare (vectori unitari) vectori
    glDepthFunc(GL_LESS); //comparaþia la ascunderea suprafeþelor
    glEnable(GL_DEPTH_TEST); //activare test adâncime

}

void CALLBACK draw(void)
{
    GLfloat low_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat more_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat most_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*  material has small ambient reflection   */
    //coeficient de reflexie pentru lumina ambientala mic
    glMaterialfv(GL_FRONT, GL_AMBIENT, low_ambient);
    glMaterialf(GL_FRONT, GL_SHININESS, 40.0);
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0);
    auxSolidTeapot(1.0);
    /*
    OBS:pt modelare este nevoie implicit de normale
        dar,daca obiectul este modelat de o functie oferita de biblioteca
        (ex:auxSolidTeapot) atunci nu mai trb calculate;
        totusi,daca obiectul e creat de programator,
        el va trb sa calculeza media aritmetica a normalelor
        la suprafata pt fiecare varf
    */
    glPopMatrix();
    glFlush();//important,deoarece goleste buffer-ul
}

void CALLBACK reshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat)h / (GLfloat)w,
            4.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-4.0 * (GLfloat)w / (GLfloat)h,
            4.0 * (GLfloat)w / (GLfloat)h, -4.0, 4.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    init();
    auxReshapeFunc(reshape);
    auxMainLoop(draw);
   /*
   OBS: daca auxReshapeFunc si auxMainLoop
        sunt trecute in corpul init
        aplicatia nu mai functioneaza
        corespunzator!
   */
    return(0);
}
