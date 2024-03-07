#include<iostream>
using namespace std;
class T{
   protected: int x;
   public: 
   T(){this->x=-1;printf("\n%s ","CONSTRUCTOR T:");}
    void info()
    {
        printf("\n %X %X",this,*this);//se apeleaza un destructor?
    }
    ~T(){printf("\n%s","DESTRUCTOR T");}
};
class Tderiv:public T
{
    public:
    float y;
    Tderiv(){this->y=3.141;printf("\n%s","CONSTRUCTOR Tderiv");}
    void setX(int x){this->x=x;printf("\n%s","metoda din Tderiv");}
    ~Tderiv(){printf("%s","DESTRUCTOR Tderiv");}
};
int main()
{
    T *var=new T;
    T var2;//doar 4 octeti ocupa;
    var2.info();
    T *var3=new Tderiv;//OBS:se intra in costructorul lui Tderiv!
   // printf("\n%f",var3->y); var3 nu il contine pe y
    printf("\n%d %d %d",sizeof(var),sizeof(var2),sizeof(int));
    delete var;
    delete var3;
    return 0;
}