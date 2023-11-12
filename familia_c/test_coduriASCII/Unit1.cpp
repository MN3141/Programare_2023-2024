//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include<string>
#include<fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
ofstream f("coduri_ASCII.txt");
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::okButtonClick(TObject *Sender)
{
       codeLabel->Caption=" ";
    for(int i=1;i<=inputEdit->Text.Length();i++)   //!! Indexarea incepe de la 1 !!!!
    {
        codeLabel->Caption = codeLabel->Caption+" "+(int)inputEdit->Text.operator [](i) ;
     f<<(int)inputEdit->Text.operator [](i)<<endl;
      }
      f<<"========="<<endl;

}
//---------------------------------------------------------------------------
