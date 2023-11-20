#include<iostream>
#include<time.h>
using namespace std;
class X //cod preluat din cartea dl-ului Breazu,pg 20
{
    int x;
    static int y;
    static int z;
    static float nr;
    //int X::z=1; asa nu se poate
    public:void Met1()
    {
        printf("\nNumar instante =%d",y); //%d printare considerand a fi un nr intreg
        printf("\nZ=%d",z); 
    }
    static float Random()
    {
        return rand()%101;
    }
    X()
    {
       
        y++;
    }
    ~X()
    {
        y--;
    }
};
int contor()
{
    static int k=0;//tehnic vorbind,compilatorul va trata k drept o variabila globala
    k++;
    return k;
}
int X::y=0; //doar asa putem initializa membrii statici ai unei clase!!!
int X::z=1;
float X::nr=0;
int main()
{
    srand(time(NULL));
    X var;
    var.Met1();
    printf("\n %f",var.Random()); //%f pt float
    float temp=X::Random(); //similar cu Math.Random() din Java
    printf("\n %f",temp);
    for(int i=0;i<10;i++)
        printf("\n %d",contor());
}