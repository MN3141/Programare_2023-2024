//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include<fstream>
using namespace std;
ofstream fout("coduri_ASCII.txt");
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

void __fastcall TForm1::btnOkClick(TObject *Sender)
{
        labelCode->Caption=" ";
    for(int i=1;i<=Memo1->Text.Length();i++)   //!! Indexarea incepe de la 1 !!!!
    {
        labelCode->Caption = labelCode->Caption+" "+(int)Memo1->Text.operator [](i) ;
     fout<<(int)Memo1->Text.operator [](i)<<endl;
      }
      fout<<"========="<<endl;        
}
//---------------------------------------------------------------------------
