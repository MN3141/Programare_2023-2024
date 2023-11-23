
/*
42 4D 3A 00 00 00 00 00 00 00 36 00 00 00 28 00 
00 00 01 00 00 00 01 00 00 00 01 00 18 00 00 00 
00 00 04 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 FF 00 00 00
*/
//FF 00 00 code for red
//map for image 1pixel.bmp
#include <iostream>
#include "bitmap.h"
using namespace std;
int main()
{
	Bitmap imago("1pixel.bmp");
	Bitmap imago2("logo_c++.bmp");
	imago.readImage();
	imago.readImage();
}

