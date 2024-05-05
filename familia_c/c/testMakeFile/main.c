#include<stdio.h>
#include "function.h"
#include "function2.h"
int main()
{
    int x;
    printf("%s","Introdu un nr:");
    scanf("%d",&x);
    if(check_number(x))
        printf("%s\n","Numarul ales este par.");
    else 
        printf("%s\n","Numarul ales nu este par.");
    msg();
    return 0;
}