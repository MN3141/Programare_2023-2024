#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "ex7.h"
#include "clase.h"

MULTIME m;

int main(void)
//*********
{
int gata=0;

   OurInitGraph();

   m += new CERC;
   m = m + new PATRAT(500,300,75,RED,"red");
   m += new CERC(100,100,25,BLUE,"blue");
   m = m + new PATRAT;
   m = m + new PATRAT(400,200,100,YELLOW,"yellow");
   m += new CERC;

   m.Afiseaza();

   while(!gata)
     switch(getch())
       {
       case ESC:
         gata=1;
         break;
       case TAB:
         ++m;
         break;
	   case UNU:    m.Get()->Creste( +10     ); m.Afiseaza();break;
	   case DOI:    m.Get()->Creste( -10     ); m.Afiseaza();break;
	   case TREI: {  if(m.NrElem()<MAX_FIGURI)
                       if(m.NrElem()%2)
                           m += new CERC;
                       else
                           m += new PATRAT;
                    m.Afiseaza();
					break;
		   }
	    case PATRU: {m.Elimina(); m.Afiseaza(); 
					break;
			}
		case CINCI:{
		ofstream fout("test.cfg");
		fout<<m;
		break;
		}
		case SASE:{
		ifstream fin("test.cfg");
		fin>>m;
		m.Afiseaza();
		break;}
        case 0:
         switch(getch())
           {
           case LEFT:  m.Get()->Muta(   -10,  0 ); break;
           case RIGHT: m.Get()->Muta(    10,  0 ); break;
           case UP:    m.Get()->Muta(     0,-10 ); break;
           case DOWN:  m.Get()->Muta(     0, 10 ); break;
           }
         m.Afiseaza();
       }
   closegraph();
   return 0;
}

void OurInitGraph()
//*****************
{
int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver,&gmode,"");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   settextjustify(CENTER_TEXT,CENTER_TEXT);
}
