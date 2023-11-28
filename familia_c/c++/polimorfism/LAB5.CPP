#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "lab5.h" 
#include "CLASE.h"

#define MAX_FIGURI 20

//variabile Globale

FIGURA *pc[MAX_FIGURI];                 // tablou de pointeri la cercuri
int NrFiguri;

CERC tf[2];                           // tablou de cercuri
PATRAT fg1(200,200,25),fg2(100,100,25,BLUE,"blue");   //cercuri definite global

int main(void)
//*********
{
int counter=0;
int FiguraCurenta=0,gata=0,k;        // variabile locale
CERC fl1(500,300,75,RED,"red"),fl2(300,300);   //cercuri definite local

  OurInitGraph();

   pc[0]=&tf[0];                     //initializare tablou pointeri la cerc
   pc[1]=&tf[1];
   pc[2]=&fg1;
   pc[3]=&fg2;
   pc[4]=&fl1;
   pc[5]=&fl2;
   pc[6]=new CERC(400,200,100,YELLOW,"yellow");   // cercuri "dinamice"
   pc[7]=new CERC;
   NrFiguri=8;

  for(k=0;k<NrFiguri;k++)            //afiseaza toate cercurile pe ecran
     pc[k]->Afiseaza();

  while(!gata)
  {
    switch(getch())
    {
      case ESC:
	  {
        gata=1;
        break;
		  }
      case TAB:
	  {
        FiguraCurenta++;
        FiguraCurenta%=NrFiguri;
        break;
		  }
		case UNU:   { pc[FiguraCurenta]->Creste(  +10  ); Afiseaza(); break;}
        case DOI:   { pc[FiguraCurenta]->Creste(  -10  ); Afiseaza();break;}
        case TREI:  { if(NrFiguri==MAX_FIGURI) break;  //prea multe figuri
                         pc[NrFiguri++]=new CERC;      //o figura noua
                      FiguraCurenta=NrFiguri-1;        //devine cea curenta
					  Afiseaza();
                      break;
			  }
        case PATRU: 
		  {  
				  if(NrFiguri==6) break;           //primele 6 nu se distrug
				  delete pc[--NrFiguri];           //distrugem ultima figura
                  if(NrFiguri==FiguraCurenta)
                      FiguraCurenta=0;             //daca era cea curenta...
					Afiseaza();  
                   break;
			  }  
	case ENTER:
		{
				pc[FiguraCurenta]->Sterge();
				if(counter%2==0)
					pc[FiguraCurenta]=new CERC(pc[FiguraCurenta]->GetX(),pc[FiguraCurenta]->GetY(),30,3,"MAGIC");
				else pc[FiguraCurenta]=new PATRAT(pc[FiguraCurenta]->GetX(),pc[FiguraCurenta]->GetY(),30,3,"MAGIC");
				counter++;
				Afiseaza();
			break;
		}
      case 0:
	  {
		switch(getch())
        {
          case LEFT: { pc[FiguraCurenta]->Muta( -10,  0 ); break;}
          case RIGHT:{ pc[FiguraCurenta]->Muta(  10,  0 ); break;}
          case UP:   { pc[FiguraCurenta]->Muta(   0,-10 ); break;}
          case DOWN: { pc[FiguraCurenta]->Muta(   0, 10 ); break;}
         
        }
       Afiseaza();
	 }
    }
  }
  
  closegraph();
  return 0;
}

void Afiseaza()
//*****************
{
    for(int k=0;k<NrFiguri;k++)                         //afiseaza toate figurile
	   {
         pc[k]->Afiseaza();
	   }
}
void OurInitGraph()
//*****************
{
int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver,&gmode,""); /* initialize graphics and local variables */

   errorcode = graphresult();     /* read result of initialization */
   if (errorcode != grOk)         /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);                    /* terminate with an error code */
   }

   settextjustify(CENTER_TEXT,CENTER_TEXT); //folosit pt ca suntem in modul grafic!
}
