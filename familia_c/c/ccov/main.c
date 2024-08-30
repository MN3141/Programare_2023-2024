/*
-fprofile-arcs -ftest-coverage <=> --coverage
CCOV=Code Coverage*/
#include<stdio.h>
#include "functions.h"

int main()
{
    int nr=numBits(-1);
    int nr2=parity(-1);
    
    printf("%d",nr);
    printf("\n%d",nr2);
}