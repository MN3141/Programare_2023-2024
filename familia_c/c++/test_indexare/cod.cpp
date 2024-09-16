#include<iostream>
#include<string.h>
#include <catch2/catch_test_macros.hpp>

using namespace std;
class Factory{ 
     char *emplyeeNames[4]; 
     int salaries[4];
    public:
    Factory() 
    {
        emplyeeNames[0]="John";
        emplyeeNames[1]="Smith";
        emplyeeNames[2]="Ivan";
        emplyeeNames[3]="Grigor";
        salaries[0]=1600;
        salaries[1]=2000;
        salaries[2]=5500;
        salaries[0]=1600;
    }
    int operator[](char *name)
    {
        for(int i=0;i<3;i++)
        {
            if(strcmp( emplyeeNames[i],name)==0)
                return this->salaries[i];
        }
        return -1;
    }
};
int main()
{
    Factory IPRS;
    cout<<IPRS["Ivan"];
}