#include "../include/glos.h"
#include "../include/openGL_headers.h"
float radius =100;
void light_init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);//pt curbe
	glEnable(GL_COLOR_MATERIAL);

	float light_pos[] = { 0,200,100,0}; //k=0 => distanta infinita
	float ambient_light[] = { 1,1,1,1};
	float diffuse_light[] = { 1,1,1,1 };
	float specular_light[] = { 1,1,1,1 };
	float diffuseMaterial[] = { 0.5,0.5,0.5,1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);

}
void shadow_init()
{

}
void draw_snow_man(float animation_angle)
{
	glPushMatrix();
	glColor3ub(255, 255, 255);
	auxSolidSphere(radius); //sphere 1

	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0,radius+ 3*radius/4 -radius/2,0);
	auxSolidSphere(3 * radius / 4); //sphere 2
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0, radius+3*radius/4 +radius/2, 0); //sphere 3
	auxSolidSphere(radius / 2);
	glPopMatrix();

	glPushMatrix(); 
	glColor3ub(195, 195, 195);
	glTranslatef(0, radius + 3 * radius / 4 + radius / 2, 0);
	glRotatef(-90, 1, 0, 0);
	auxSolidCone(radius / 2 -10, 2*radius); //hat
	glPopMatrix();
	
	glPushMatrix();
	//glColor3ub(255, 133, 51);
	//glColor4b(255, 133, 51, 1);
	glTranslatef(0, radius + 3 * radius / 4 + radius / 2 , radius/4+10);
	glRotatef(39, 1, 0, 0);
	float nose_color[] = { 1., 0.52, 0.2, 1.0 }; // Orange color
	glMaterialfv(GL_FRONT, GL_DIFFUSE, nose_color);
	auxSolidCone(radius / 4, radius / 4 +20);//nose
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(128, 64, 0);
	glTranslatef(3 * radius / 4 -10, radius + 3 * radius / 4 - radius / 2, 0);
	glRotatef(45, 0, 0, 1);
	auxSolidCylinder(radius/10, radius); //left hand
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 64, 0);
	glTranslatef(-(3 * radius / 4 - 10), radius + 3 * radius / 4 - radius / 2, 0);
	glRotatef(-45-animation_angle, 0, 0, 1);
	auxSolidCylinder(radius / 10, radius); //right hand
	glPopMatrix();

	glPopMatrix();
}