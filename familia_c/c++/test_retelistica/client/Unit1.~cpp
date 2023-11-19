//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfClient *fClient;
//---------------------------------------------------------------------------
__fastcall TfClient::TfClient(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfClient::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------
void __fastcall TfClient::btnSendClick(TObject *Sender)
{
         ClientSocket1->Socket->SendText("BALGRAD pe fir");
}
//---------------------------------------------------------------------------
