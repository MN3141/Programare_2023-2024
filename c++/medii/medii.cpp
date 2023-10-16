#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("data.txt");
int n;
int *grades= new int [100];
void Sort(int *a, int n)
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = i+1 ; j < n; j++)
		{
			if (*(a+i)> *(a+j)) swap(*(a+i),*(a+j));
		}
	}
}
void Init()
{
	f>>n;
	for(int i=0;i<n;i++)
		f>>*(grades+i);
	Sort(grades,n);
	
}
float mean(int* grades,int begin,int end)
{
	float sum=0;
	float x;
	for(int i=begin;i<end;i++)
		sum=sum+*(grades+i);
	x=sum/(end-begin);
	return x;

}
float geomean(int* grades,int begin,int end)
{
	double prod=1;
	double x;
	for(int i=begin;i<end;i++)
		prod=prod* *(grades+i);
	double exponent=1./(end-begin);
	x= pow(prod,exponent);
	return x;
}
float median(int* grades,int begin,int end)
{
	int number=end-begin;
	float x;
	if((end-begin)%2==0)
		{
			number=number/2;
			x=(*(grades+number -1)+*(grades+number +1))/2.;
		}
	else 
		x= *(grades+number/2);
	return x;

}
int main()
{
	Init();
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<*(grades+i)<<' ';
	cout<<endl;
	cout<<mean(grades,0,n)<<endl;
	cout<<geomean(grades,0,n)<<endl;
	cout<<median(grades,0,n)<<endl;
}
