#include <iostream>
using namespace std;
class POZITIE
      {
      public:
             POZITIE();
             POZITIE(int x0,int y0);
        void Muta(int dx,int dy);
      protected:
        int  x;
        int  y;
      };

class FIGURA : public POZITIE
      {
      protected:
         int  r;
         int  c;
         char *Nume;
      public:
            FIGURA();
            FIGURA(int x0,int y0,int r0,int c0,char *n0);
      virtual ~FIGURA();
              void Muta(int dx,int dy);
              void Creste(int dr);
      virtual void Afiseaza()=0;
      virtual void Sterge()=0;
	  virtual char getFigure()=0;
	  friend ostream &operator<<(ostream &flux,FIGURA &f)
	  {
		  flux<<f.getFigure()<<' '<<f.x<<' '<<f.y<<' '<<f.r<<' '<<f.c<<' '<<f.Nume<<endl;
		  return flux;
	  }
	  friend istream &operator>>(istream &flux,FIGURA &f)
	  {
		  
		  flux>>f.x>>f.y>>f.r>>f.c>>f.Nume;
		  return flux;
	  }
	  };

class CERC : public FIGURA
      {
      public:
              CERC();
              CERC(int x0,int y0,int r0,int c0,char *n0="CERC");
         void Afiseaza();
         void Sterge();
		 char getFigure();
      };

class PATRAT : public FIGURA
      {
      public:
              PATRAT();
              PATRAT(int x0,int y0,int r0,int c0,char *n0="PATRAT");
         void Afiseaza();
         void Sterge();
		 char getFigure();
      };

#define MAX_FIGURI 20

class MULTIME
      {
        int      NrFiguri;
        int      FiguraCurenta;
        FIGURA  *pe[MAX_FIGURI];
      public:
                 MULTIME();
        void     Goleste();
        void     Afiseaza();
        void     Elimina();
        FIGURA*  Get();
        int      NrElem();
        void     operator ++();
        void     operator += ( FIGURA* f );
        MULTIME& operator +  ( FIGURA* f );
		friend ostream &operator<<(ostream &flux,MULTIME &m)
		{
			flux<<m.NrFiguri<<' '<<m.FiguraCurenta<<endl;
			for(int i=0;i<m.NrFiguri;i++)
			{
				flux<<*(m.pe[i]);
			}
			return flux;
		}
		friend istream &operator>>(istream &flux,MULTIME &m)
		{
			m.Goleste();
			char temp=0;
			flux>>m.NrFiguri>>m.FiguraCurenta;
			for(int i=0;i<m.NrFiguri;i++)
			{
				delete m.pe[i];
				flux>>temp;
				if(temp=='c') m.pe[i]=new CERC;
				else m.pe[i]=new PATRAT;
				flux>>*(m.pe[i]);
			}
			
			return flux;
		}
      };
