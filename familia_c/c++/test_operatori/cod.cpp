#include <iostream>
using namespace std;
class Tablou{
    int v[100];
    int indexCurrent;
    public:
    Tablou()
    {
        for(int i=0;i<100;i++)
            this->v[i]=0;
        this->indexCurrent=0;
    }
    Tablou(int v[],int n)
    {
        this->indexCurrent=0;
        for(int i=0;i<n;i++)
        {
        this->v[this->indexCurrent]=v[i];
        this->indexCurrent++;
        }
        this->indexCurrent=this->indexCurrent-1;
    }
    void Print()
    {
        int index=this->indexCurrent;
         for(int i=0;i<=index;i++)
            cout<<this->v[i]<<" ";
        cout<<endl;
    }
    void Push(int val)
    {
     this->v[this->indexCurrent]=val;
     this->indexCurrent++;
    }
     void operator++()
    {
     this->v[this->indexCurrent]=this->v[this->indexCurrent]+1;   
    }
    friend void operator++(Tablou &tab);
    friend void operator+(Tablou &tab,int val);
};
void operator++(Tablou &tab)
    {
        int index=tab.indexCurrent;
         for(int i=0;i<index;i++)
            tab.v[i]=tab.v[i]+1;
    }
void operator+(Tablou &tab,int val)
{
      int index=tab.indexCurrent;
         for(int i=0;i<index;i++)
            tab.v[i]=tab.v[i]+val;
}
int main()
{
  int v[3]={0,1,6};
  Tablou y(v,3);
  y.Print();
  y.operator++();
  y.Print();
}