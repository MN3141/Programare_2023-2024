#include <iostream>
#include "matrix.h"
using namespace std;
int main()
{
	Matrix M(4),N(2,1);
	int v[] = {1,2,-1,4,11};
	int w[] = { 1,2,3,4,5 };
	Matrix P(v, 5, 4, 4);
	Matrix a =P;
	a.Print();
	Matrix b(v, 4, 4, 1);
	a = a * b;
	a.Print();
}

