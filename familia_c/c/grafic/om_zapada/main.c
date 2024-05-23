#include<stdio.h>
#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include "draw.h"
int angulus = 0;
void CALLBACK debug_rot0()
{
    angulus = (angulus + 1) % 361;
    printf("Rot0: %d\n", angulus);
}
void CALLBACK debug_rot1()
{
    angulus=(angulus - 1) % 361;
    printf("Rot1: %d\n", angulus);
}
void CALLBACK camera_front()
{

}
void CALLBACK camera_back()
{

}
void CALLBACK camera_left()
{

}
void CALLBACK camera_right()
{

}
void CALLBACK draw_scene(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glRotatef(angulus,1,0,0);
    draw_snow_man();
    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1000, 1000, -1000 * (GLfloat)h / (GLfloat)w,//pentru dimensiuni logice
            1000 * (GLfloat)h / (GLfloat)w, -1000, 1000);
    else
        glOrtho(-300 * (GLfloat)w / (GLfloat)h,
            300 * (GLfloat)w / (GLfloat)h, -1000, 1000, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);//setare buffer
    auxInitPosition(00, 00, 1000, 1000);//setare coordonate fereastra
    auxInitWindow("Om zapada");

    auxKeyFunc(AUX_LEFT, camera_left);
    auxKeyFunc(AUX_RIGHT, camera_right);
    auxKeyFunc(AUX_UP, camera_front);
    auxKeyFunc(AUX_DOWN, camera_back);
    auxKeyFunc(AUX_a, debug_rot0);
    auxKeyFunc(AUX_d, debug_rot1);

    auxReshapeFunc(myReshape);
    auxMainLoop(draw_scene);
}
int main(int argc, char** argv)
{
    init();
    return 0;
}
