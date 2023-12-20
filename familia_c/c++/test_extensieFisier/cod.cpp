#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    ofstream fout("test.iprs",ios::binary);
    ifstream fin("test.ipts",ios::binary);
    char *buffer=new char[100];
    strcpy(buffer,"test");
    fout.write(buffer,4);
    fout.close();
    fin.close();
    fin.read(buffer,2);
    fin.close();
    for(int i=0;i<4;i++)
        cout<<*(buffer+i);
    cout<<endl;
    ifstream fin2("test2.iprs",ios::binary);
    fin2.read(buffer,5);
      for(int i=0;i<4;i++)
        cout<<*(buffer+i);
    cout<<endl;
    ifstream fin3("test3.iprs",ios::binary);
    int k=0;
    char *buffer2=new char[100];
    while(!fin3.eof())
    {
        fin3.read(buffer,1);
        buffer2[k]=*buffer;
        k++;
    }
    fin3.close();
    k--;//nu luam in considerare caracterul nul
     for(int i=0;i<k;i++)
        cout<<*(buffer2+i);
    cout<<endl<<"Operation succesful.";
    delete buffer;
}