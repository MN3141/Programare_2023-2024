#include <graphics.h>

class POZITIE                                  //clasa pozitie
{
  public:                                      //membrii publici
         POZITIE();                            //constructor fara parametrii
         POZITIE(int x0,int y0);               //constructor cu parametrii
    int  GetX   ()             { return(x); }; //metoda citire membru x
    int  GetY   ()             { return(y); }; //metoda citire membru y
    void Muta   (int dx,int dy); 
  protected:                                   //membrii protected
    int  x;
    int  y;
};

class FIGURA : public POZITIE 
{
protected:
    int  r;                                    
    int  c;
    char *Nume;
  public:                                      //metode PUBLICE
	FIGURA ();                               //constructor fara parametrii
	FIGURA (int x0,int y0,int r0=20,int c0=RED,char *n0="IMPLICIT");
	~FIGURA ();                              //destructor
    void Muta(int dx,int dy);                  //metode publice
 virtual void Afiseaza()=0;
    void Creste(int dr);
 virtual void Sterge()=0;                             //metoda PRIVATA
};
class CERC: public FIGURA
{
public:
	CERC();
	CERC(int x0,int y0,int r0=20,int c0=RED,char *n0="IMPLICIT");
	~CERC();
	void Afiseaza();
    void Sterge();   
};
class PATRAT:public FIGURA
{
public:
	PATRAT();
	PATRAT(int x0,int y0,int r0=20,int c0=RED,char *n0="IMPLICIT");
	~PATRAT();
	void Afiseaza();
 void Sterge();
	
};