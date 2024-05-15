#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SQUARE(x) x*x
/*in unele cazuri e mai eficient
  sa folosim macro-ul cu parametrii
  decat functii,deoarece nu e
  nevoie de incarcarea si descarcarea stivei*/
int main(int argc,char **argv)
{
    #ifndef EXIT_SUCCES//nu e structura de control a aplicatiei,ci a compilarii
        printf("Macro-ul EXIT_SUCCES nu exista. \n");
    #elif
        printf("Macro-ul EXIT_SUCCES exista.\n");
    #endif
    //dummy comment
    printf("Nume cod sursa: %s \n",argv[0]);
    if(strlen(argv[1])>0)
    printf("%d",SQUARE(atoi(argv[1])));//nu merge pare-se pt variabile de tip flotant
    //atoi=ASCII To Integer
    return 0;
}