#ifndef DRAW
#define DRAW
void light_init();
void draw_snow_man(float animation_angle);
void MatriceUmbra(float puncte[3][3],
	float mat[4][4]);
void calcCoeficientiPlan(float P[3][3], float coef[4]);
void draw_plane();
void draw_sun();
#endif