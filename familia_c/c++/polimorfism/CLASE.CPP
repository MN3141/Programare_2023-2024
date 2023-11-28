#include <graphics.h>
#include <string.h>
#include <conio.h>
#include "CLASE.h"

//~~~~~~~~~~~~~~~~~~
//  clasa POZITIE
//~~~~~~~~~~~~~~~~~~

POZITIE::POZITIE()                     //constructor fara parametrii
//****************
{
    x =   320;
    y =   240;
}

POZITIE::POZITIE(int x0,int y0)        //constructor cu param
//*****************************
{
    x = x0;
    y = y0;
}

void POZITIE::Muta(int dx,int dy)
//*******************************
{
    x += dx;
    y += dy;
}

//~~~~~~~~~~~~~~
//  clasa FIGURA
//~~~~~~~~~~~~~~

FIGURA::FIGURA()                       //constructor fara parametrii
//**********
{
    r =    50;
    c = WHITE;
    Nume = (char*)malloc(strlen("CERC")+1); //aloca memoria necesara sir
    strcpy(Nume,"CERC");                    //copiaza un sir in Nume
}

FIGURA::FIGURA(int x0,int y0,int r0,int c0, char *n0):POZITIE(x0,y0)
//**************************************************************
{
	r = r0;
	c = c0;
	Nume = (char*)malloc(strlen(n0)+1);    //aloca memoria necesara
	strcpy(Nume,n0);
}
FIGURA::~FIGURA()
{
	
}

void FIGURA ::Sterge()
{
}
void FIGURA ::Afiseaza()
{
}
void FIGURA ::Muta(int dx,int dy)
//****************************
{
    Sterge();                          //stergere figura
    POZITIE::Muta(dx,dy);              //mutare
    Afiseaza();                        //afisare in noua pozitie
}

void FIGURA ::Creste(int dr)
//***********************
{
    Sterge();                          //stergere
    r += dr;                           //redimensionare
    Afiseaza();                        //afisare cu noua dimensiune
}
//~~~~~~~~~~~~~~
//  clasa CERC
//~~~~~~~~~~~~~~
CERC::CERC():FIGURA()
{

}
CERC::CERC(int x0,int y0,int r0,int c0, char *n0):FIGURA(x0,y0, r0, c0, n0)
{
	
}
CERC::~CERC()                      //destructor
//***************
{
    Sterge();                          //sterge de pe ecran
    free(Nume);                        //elibereaza memoria alocata
}

void CERC::Sterge()
{
	setcolor(BLACK);
    circle(x,y,r);                     //stergere prin desenare cu negru
    outtextxy(x,y,Nume);               //sterge text din mijlocul figurii
}
void CERC::Afiseaza()
{
	setcolor(c);
    circle(x,y,r);                     //desenare figura pe ecran
    outtextxy(x,y,Nume);               //scrie text in mijlocul figurii
}
//~~~~~~~~~~~~~~
//  clasa PATRAT
//~~~~~~~~~~~~~~
PATRAT::PATRAT():FIGURA()
{
}
PATRAT::PATRAT(int x0,int y0,int r0,int c0, char *n0):FIGURA(x0,y0, r0, c0, n0)
{
	
}
PATRAT::~PATRAT()
{
	Sterge();                    
    free(Nume);
}
void PATRAT::Sterge()
{
	setcolor(BLACK);
    rectangle(x-r,y-r,x+r,y+r);                   
    outtextxy(x,y,Nume);   
}
void PATRAT::Afiseaza()
{
	setcolor(c);
    rectangle(x-r,y-r,x+r,y+r);                   
    outtextxy(x,y,Nume);  
}