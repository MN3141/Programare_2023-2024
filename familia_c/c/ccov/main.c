/*
-fprofile-arcs -ftest-coverage <=> --coverage
CCOV=Code Coverage*/
#include<stdio.h>
int numBits(int num)
{
    int counter=0;
    for(int i=0;i<32;i++)
        counter+=(num & (1<<i))!=0;//OBS:(var!=0) este 1 daca var diferit de 0,si 0 daca nu
    return counter;
}
int parity(int num)
{
    int parity=0;
    for(int i=0;i<32;i++)
        parity+=(num & (1<<i))!=0;
    parity=(parity%2==0);//parity%2==0 e o expresie logica,deci poate fi 1 sau 0
    return parity;
}
int main()
{
    int nr=numBits(-1);
    int nr2=parity(-1);
    printf("%d",nr);
    printf("\n%d",nr2);
}