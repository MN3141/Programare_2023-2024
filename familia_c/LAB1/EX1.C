#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ex1.h" //includerea bibliotecii proprii ex1.h care trebuie 
                 //sa fie in directorul curent. 
#define NUM 10 //avem doar 16 culori la dispozitie!!!
// prototipuri de functii
int Circulus[10][4];
void OurInitGraph(void);
struct Cerc
{
int x,y,r,c;	
};
void Muta(int *x,int *y,int r,int c,int dx,int dy);
void Mutapp(Cerc *x,int dx,int dy); //pp=++
// variabile Globale, pentru un cerc vom avea urmatoarele date:
//  - x, y coordonatele centrului cercului
//  - r raza cercului
//  - c culoarea cercului

// se vor defini 3 cercuri    

\

Cerc G[10];
void Init()
{
	for(int i=0;i<NUM;i++)
	{
		G[i].x=200+i*10;
		G[i].y=200+i*10;	
		G[i].r=100+i*10;
		G[i].c=i+1;
	}
}
int main(void)
{
// variabile locale

int CercCurent=0; 

// este variabila care ne pastreaza cercul curent ea va putea lua 3 valori:
// 0 - pentru cercul x1, y1, r1, c1
// 1 - pentru cercul x2, y2, r2, c2
// 2 - pentru cercul x3, y3, r3, c3
//...
// 9 -pt cercul 10
int gata=0;
int dx,dy; 

// cod
	Init();
   OurInitGraph(); //se face trecerea in modul grafic

	for(int i=0;i<NUM;i++)
	{
		setcolor(G[i].c);
		circle(G[i].x,G[i].y,G[i].r);
	}

// se intra intr-o bucla in care se ramane atata timp cat gata=0
   while(!gata)
     switch(getch())      //se asteapta apasarea unei taste
      {
       case ESC:          //daca s-a apasat ESC atunci se iasa din bucla
         gata=1;          //prin valoarea 1 pe care o primeste gata
         break;
       case TAB:          //daca s-a apasat TAB se trece la urmatorul cerc
         CercCurent++;    //trecem la cercul urmator
         CercCurent%=10;   //dupa cercul 2 urmeaza cercul 0 
         break;
       case 0:            //la apasarea unei sageti se genereaza intai 0. 
         switch(getch())  //apoi codul specific
          {
           case LEFT:  dx=-10;dy=  0;break;
           case RIGHT: dx= 10;dy=  0;break;
           case UP:    dx=  0;dy=-10;break;
           case DOWN:  dx=  0;dy= 10;break;
           default:    dx=  0;dy=  0;break;
          }
		 Mutapp(&G[CercCurent],dx,dy);
       }
   closegraph();		//inchiderea modului grafic
   return 0;
}

void Muta(int *x,int *y,int r,int color,int dx,int dy)
//****************************************************
//functie care face mutarea unui cerc cu deplasamentele
//dx (pe orizontala) si dy (pe verticala)
{
  setcolor(BLACK);  //sterge cercul de pe pozitia veche, prin 
  circle(*x,*y,r);  //scrierea unui cerc de culoarea fondului (negru) peste el

  *x += dx;         //sunt modificate coordonatele centrului cercului
  *y += dy;

  setcolor(color);
  circle(*x,*y,r);  //desenare in noua pozitie a cercului
}

void Mutapp(Cerc *c,int dx,int dy)
{
	setcolor(BLACK);
	circle(c->x,c->y,c->r);
	c->x=c->x+dx;
	c->y=c->y+dy;
	setcolor(c->c);
	circle(c->x,c->y,c->r);

}
void OurInitGraph()
//*********************
// functie care face trecerea din modul text in modul grafic
{
int gdriver = DETECT, gmode, errorcode;  //declarare de variabile locale

  initgraph(&gdriver,&gmode,"");   //initializeaza modul grafic 
  errorcode = graphresult();       //citeste rezultatul initializarii
   if (errorcode != grOk)          //se testeaza daca a aparut o eroare la 
                                   //initializare, in caz de eroare se afiseaza 
    {                              //eroarea si apoi se inchide programul
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
    }
}
