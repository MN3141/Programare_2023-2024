#include "../include/glos.h"
#include "../include/openGL_headers.h"
float radius =100;
void light_init()
{

}
void shadow_init()
{

}
void draw_snow_man()
{
	glPushMatrix();
	glColor3ub(255, 255, 255);
	auxSolidSphere(radius);

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0,radius+ 3*radius/4 -radius/2,0);
	auxSolidSphere(3 * radius / 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, radius+3*radius/4 +radius/2, 0);
	auxSolidSphere(radius / 2);
	glPopMatrix();

	glPushMatrix(); 
	glColor3ub(195, 195, 195);
	glTranslatef(0, radius + 3 * radius / 4 + radius / 2, 0);
	glRotatef(-90, 1, 0, 0);
	auxSolidCone(radius / 2 -10, 2*radius); //hat
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(255, 133, 51);
	glTranslatef(0, radius + 3 * radius / 4 + radius / 2 , radius/4+35);
	glRotatef(39, 1, 0, 0); //39
	auxSolidCone(radius / 4, radius / 4);//nose
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(128, 64, 0);
	glTranslatef(100, 0, 0);
	glRotatef(45, 0, 0, 1);
	auxSolidCylinder(radius/10, radius); //right hand
	glPopMatrix();

	glPopMatrix();
}