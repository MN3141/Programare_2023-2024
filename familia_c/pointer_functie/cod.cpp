#include<iostream>
using namespace std;
bool condition(int x,int y)
{
    return (x>y);
}
void selectSort(int v[],int n,bool(*pointerFunction)(int ,int ))
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            {
                if(condition(v[i],v[j])>0)
                    swap(v[i],v[j]);
            }
    }
}
void print(int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
    cout<<endl;
}
int main()
{
        int v[]={1,5,6,8,0};
        print(v,5);
        selectSort(v,5,condition);
        print(v,5);

}