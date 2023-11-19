#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h> //for the delay function
#define num 50
#define X 320
#define Y 240
struct circulus
{
	int x,y,r,c;
};
circulus g[num];
void InitCirc()
{
	for(int i=0;i<num;i++)
	{
		g[i].x=X;
		g[i].y=Y;
		g[i].r=10 +10*i;
		g[i].c=i%14+1;
	}
}
void OurInitGraph(void);
void OurInitGraph();
void Draw(circulus g)
{
	
	setcolor(g.c);
	circle(g.x,g.y,g.r);
	
}
void Erase(circulus g)
{
	
	setcolor(BLACK);
	circle(g.x,g.y,g.r);
	
}
int main()
{
	InitCirc();
	OurInitGraph();
	int x=0;
	bool k=1;
	while(k) 
	{
		
		for(int i=0;i<num;i++)
		{
				Draw(g[i]);
				delay(100);
		}
				for(int i=0;i<num;i++)
		{
				Erase(g[i]);
				delay(100);
		}
		
	}
}
void OurInitGraph()
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
}