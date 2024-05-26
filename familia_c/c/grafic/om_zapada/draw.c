#include "../include/glos.h"
#include "../include/openGL_headers.h"
#include<math.h>
const float radius =100;
float light_pos[] = { 0,200,100,0 }; //k=0 => distanta infinita
void light_init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);//pt curbe
	glEnable(GL_COLOR_MATERIAL);

	
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
void draw_plane()
{
	//ordinea punctelor musai in ordine trigonometrica
	glPushMatrix();
	glColor3ub(255, 255, 0);
	glBegin(GL_QUADS);
	glVertex3f(500,-110,-500);
	glVertex3f(500, -110, 500);
	glVertex3f(-500, -110, 500);
	glVertex3f(-500, -110, -500);
	glEnd();
	glPopMatrix();
}
void calcCoeficientiPlan(float P[3][3], float coef[4])
{
	float v1[3], v2[3];
	float length;
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;
	//calculeazã doi vectori din trei puncte
	v1[x] = P[0][x] - P[1][x];
	v1[y] = P[0][y] - P[1][y];
	v1[z] = P[0][z] - P[1][z];

	v2[x] = P[1][x] - P[2][x];
	v2[y] = P[1][y] - P[2][y];
	v2[z] = P[1][z] - P[2][z];

	//se cacluleazã produsul vectorial al celor doi vectori
	// care reprezintã un al treilea vector perpendicular pe plan 
	// ale cãrui componente sunt chiar coeficienþii A, B, C din ecuaþia planului
	coef[x] = v1[y] * v2[z] - v1[z] * v2[y];
	coef[y] = v1[z] * v2[x] - v1[x] * v2[z];
	coef[z] = v1[x] * v2[y] - v1[y] * v2[x];
	//normalizeazã vectorul
	length = (float)sqrt((coef[x] * coef[x]) + (coef[y] * coef[y]) + (coef[z] * coef[z]));
	coef[x] /= length;
	coef[y] /= length;
	coef[z] /= length;
}
void MatriceUmbra(float puncte[3][3], float mat[4][4])
{
	GLfloat coefPlan[4];
	GLfloat temp;
	//determinã coeficienþii planului
	calcCoeficientiPlan(puncte, coefPlan);
	//determinã si pe D
	coefPlan[3] = -(
		(coefPlan[0] * puncte[2][0]) +
		(coefPlan[1] * puncte[2][1]) +
		(coefPlan[2] * puncte[2][2]));
	//temp=A*xL+B*yL+C*zL+D*w
	temp = coefPlan[0] * light_pos[0] +
		coefPlan[1] * light_pos[1] +
		coefPlan[2] * light_pos[2] +
		coefPlan[3] * light_pos[3];
	//prima coloanã
	mat[0][0] = temp - light_pos[0] * coefPlan[0];
	mat[1][0] = 0.0f - light_pos[0] * coefPlan[1];
	mat[2][0] = 0.0f - light_pos[0] * coefPlan[2];
	mat[3][0] = 0.0f - light_pos[0] * coefPlan[3];
	//a doua coloana
	mat[0][1] = 0.0f - light_pos[1] * coefPlan[0];
	mat[1][1] = temp - light_pos[1] * coefPlan[1];
	mat[2][1] = 0.0f - light_pos[1] * coefPlan[2];
	mat[3][1] = 0.0f - light_pos[1] * coefPlan[3];
	//a treia coloana
	mat[0][2] = 0.0f - light_pos[2] * coefPlan[0];
	mat[1][2] = 0.0f - light_pos[2] * coefPlan[1];
	mat[2][2] = temp - light_pos[2] * coefPlan[2];
	mat[3][2] = 0.0f - light_pos[2] * coefPlan[3];
	//a patra coloana
	mat[0][3] = 0.0f - light_pos[3] * coefPlan[0];
	mat[1][3] = 0.0f - light_pos[3] * coefPlan[1];
	mat[2][3] = 0.0f - light_pos[3] * coefPlan[2];
	mat[3][3] = temp - light_pos[3] * coefPlan[3];
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
void draw_sun()//sursa de lumina
{

}