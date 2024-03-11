#include<iostream>
using namespace std;
class T{
   protected: int x;
   public: 
   T(){this->x=-1;printf("\n%s ","CONSTRUCTOR T:");}
   virtual void info()
    {
        printf("\n %X",&this->x);
        printf("\n %X %X",this,*this);
        //se apeleaza un destructor?
        //this->adresa de unde incepe obiectul
        //*this->continutul acelei adrese de memorie
        //OBS:-daca metoda nu e virtuala,&this->x coincide cu *this
        //    -daca metoda e virtuala,&this->x difera cu 8 biti fata de *this(pointer VMT?) 
    }
    ~T(){printf("\n%s","DESTRUCTOR T");}
};
class Tderiv:public T
{
    float y;
    public:
    Tderiv(){this->y=3.141;printf("\n%s","CONSTRUCTOR Tderiv");}
    void info()
    {
        printf("\n %s %X","ADR x:",&this->x);
        printf("\n %s %X","ADR y:",&this->y);
        printf("\n %X %X",this,*this);
    }
    void setX(int x){this->x=x;printf("\n%s","metoda din Tderiv");}
    ~Tderiv(){printf("\n %s","DESTRUCTOR Tderiv");}
};
void test0(){
    //testare dimensiuni si pointer this
        T *var=new T;
        T var2;
        var->info();
        var2.info();
        T *var3=new Tderiv;//OBS:se intra in costructorul lui Tderiv!
        var3->info();
        printf("\n%d %d %d",sizeof(var),sizeof(var2),sizeof(int));
        //OBS:pointer_VMT ocupa 8B,membrul x ocupa 4B;pt o buna aliniera se mai pun 4B de padding!
        //OBS:un obiect poate ocupa mai mult spatiu in memorie decat un pointer de tipul aceleasi clase
        //OBS:var2.info() <=> info(&var2)!
        delete var;
        delete var3;
}
void test1()
{
    //testare pointer de tip void
    void *var=NULL;
    var=(int *)malloc(4);  
    int x=10;
    var=&x;  
    printf("\n %X %d ",var,*(int*)var);

}
int main()
{
   //test0();
   test1();
    return 0;
}