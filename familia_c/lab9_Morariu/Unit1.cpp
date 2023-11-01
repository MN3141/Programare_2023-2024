//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfMain::btnExitClick(TObject *Sender)
{
                exit(0);        
}
//---------------------------------------------------------------------------
void __fastcall TfMain::btnUnuClick(TObject *Sender)
{
        fMain->IText->Caption=fMain->btnUnu->Caption;        
}
//---------------------------------------------------------------------------
void __fastcall TfMain::btnEditClick(TObject *Sender)
{
        fEdit->Show();
        fMain->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TfMain::btnConfigClick(TObject *Sender)
{
        fConfig->Show();
        fMain->Hide();
}
//---------------------------------------------------------------------------
