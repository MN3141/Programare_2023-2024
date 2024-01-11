#include <graphics.h>
#include <string>


#include "clase.h"

//~~~~~~~~~~~~~~~~~~
//  clasa POZITIE
//~~~~~~~~~~~~~~~~~~

POZITIE::POZITIE()
//******************
{
	x =   320;
	y =   240;
}

POZITIE::POZITIE(int x0,int y0)
//*******************************
{
	x = x0;
	y = y0;
}

void POZITIE::Muta(int dx,int dy)
//********************************
{
	x+=dx;
	y+=dy;
}

//~~~~~~~~~~~~~~~~
//  clasa FIGURA
//~~~~~~~~~~~~~~~~

FIGURA::FIGURA():POZITIE()
//*************************
{
	r =    50;
	c = WHITE;
	Nume = (char*)malloc(strlen("FIGURA")+1); // aloca memorie suplimentara
	strcpy(Nume,"FIGURA");

}

FIGURA::FIGURA(int x0,int y0,int r0,int c0, char *n0):POZITIE(x0,y0)
//*******************************************************************
{
	r = r0;
	c = c0;
	Nume = (char*)malloc(strlen(n0)+1); // aloca memorie suplimentara
	strcpy(Nume,n0);
}

FIGURA::~FIGURA()
//***************
{
	free(Nume);   // elibereaza memoria suplimentara alocata
}

void FIGURA::Muta(int dx,int dy)
//******************************
{
      Sterge();               //stergere
      POZITIE::Muta(dx,dy);  //mutare
      Afiseaza();             //afisare in noua pozitie
}

void FIGURA::Creste(int dr)
//*************************
{
      Sterge();               //stergere
      r+=dr;                  //redimensionare
      Afiseaza();             //afisare cu noua dimensiune
}

//~~~~~~~~~~~~~~
//  clasa CERC
//~~~~~~~~~~~~~~

CERC::CERC():FIGURA()
//*******************
{
}

CERC::CERC(int x0,int y0,int r0,int c0, char *n0):FIGURA(x0,y0,r0,c0,n0)
//**********************************************************************
{
}

void CERC::Sterge()
//*****************
{
      setcolor(BLACK);
      circle(x,y,r);
      if(Nume!=NULL)
         outtextxy(x,y,Nume);
}

void CERC::Afiseaza()
//*******************
{
      setcolor(c);
      circle(x,y,r);
      if(Nume!=NULL)
         outtextxy(x,y,Nume);
}
char CERC::getFigure()
{
	return 'c';
}
//~~~~~~~~~~~~~~~~
//  clasa PATRAT
//~~~~~~~~~~~~~~~~

PATRAT::PATRAT():FIGURA()
//***********************
{
}

PATRAT::PATRAT(int x0,int y0,int r0,int c0, char *n0):FIGURA(x0,y0,r0,c0,n0)
//**************************************************************************
{
}

void PATRAT::Sterge()
//*******************
{
      setcolor(BLACK);
      rectangle(x-r,y-r,x+r,y+r);
      if(Nume!=NULL)
         outtextxy(x,y,Nume);
}

void PATRAT::Afiseaza()
//*********************
{
      setcolor(c);
      rectangle(x-r,y-r,x+r,y+r);
      if(Nume!=NULL)
         outtextxy(x,y,Nume);
}
char PATRAT:: getFigure()
{
	return 'p';
}

//~~~~~~~~~~~~~~~~~
//  clasa MULTIME
//~~~~~~~~~~~~~~~~~

MULTIME::MULTIME()
//****************
{
      NrFiguri=0;
      FiguraCurenta=0;
}

void MULTIME::Goleste()
//*********************
{
int k;
      for(k=0;k<NrFiguri;k++)
         {
         pe[k]->Sterge();  // stergere de pe ecran
         delete pe[k];     // stergere din memorie
         }
      NrFiguri=0;
      FiguraCurenta=0;
}

void MULTIME::Afiseaza()
//**********************
{
int k;
      for(k=0;k<NrFiguri;k++)
         pe[k]->Afiseaza();
}

FIGURA* MULTIME::Get()
//********************
{
	return(pe[FiguraCurenta]);
}

int MULTIME::NrElem()
//*******************
{
	return(NrFiguri);
}

void MULTIME::operator++()
//************************
{
	FiguraCurenta++;
	FiguraCurenta%=NrFiguri;
}

void MULTIME::operator += ( FIGURA* f)
//************************************
{
      if(NrFiguri==MAX_FIGURI)
         return;                                      // nu mai putem insera
      memmove(&pe[FiguraCurenta]+1,&pe[FiguraCurenta],
         (NrFiguri-FiguraCurenta)*sizeof(pe[0]) );    // facem loc
      pe[FiguraCurenta]=f;                            // inserare figura noua
      NrFiguri++;
}

MULTIME& MULTIME::operator + ( FIGURA* f)
//***************************************
{
      if(NrFiguri==MAX_FIGURI)
         return(*this);                               // nu mai putem insera
      memmove(&pe[FiguraCurenta]+1,&pe[FiguraCurenta],
         (NrFiguri-FiguraCurenta)*sizeof(pe[0]) );    // facem loc
      pe[FiguraCurenta]=f;                            // inserare figura noua
      NrFiguri++;
      return(*this);                                  // returnam multimea
}

void MULTIME::Elimina()
//*********************
{
      if(NrFiguri==1)
         return;                                      // lista sa nu fie vida
      pe[FiguraCurenta]->Sterge();                    // stergere de pe ecran
      delete pe[FiguraCurenta];                       // distrugere element
      memmove(&pe[FiguraCurenta],&pe[FiguraCurenta]+1,
         (NrFiguri-FiguraCurenta)*sizeof(pe[0]) );    // mutare in multime
      NrFiguri--;
      if(FiguraCurenta==NrFiguri)
         FiguraCurenta--;
}