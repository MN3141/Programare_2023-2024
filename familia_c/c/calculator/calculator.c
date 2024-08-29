#include "calculator.h"

double add(double a,double b)
{
    return a+b;
}

double multiply(double a,double b)
{
    return a*b;
}

double divide(double a,double b)
{
    if(b==0)
        return NULL_DIVIDE_ERROR;
    else
        return a/b;
}

byte byte_not(byte a)
{
    return ~a;
}
