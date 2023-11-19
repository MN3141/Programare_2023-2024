//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include<fstream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnAddClick(TObject *Sender)
{
         ifstream fin("logo.bmp", ios_base::in | ios_base::binary );  //83499 de citiri?
       char *s=new char[15];
       for(int i=0;i<500;i++)  //la 10000 merge foarte greu
       {
               fin.read(s,15);
               for(int j=0;j<15;j++)
                {
                   *(s+j)=*(s+j)+65; //conversie in ASCII
                   if(*(s+j) >90 || *(s+j)<65)
                   *(s+j)=65;

                }
               memo1->Text=memo1->Text+s;
       }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::clearBtnClick(TObject *Sender)
{
        memo1->Text=" ";        
}
//---------------------------------------------------------------------------
