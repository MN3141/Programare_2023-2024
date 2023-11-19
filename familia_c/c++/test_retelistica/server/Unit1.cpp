//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfServer *fServer;
//---------------------------------------------------------------------------
__fastcall TfServer::TfServer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfServer::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------
void __fastcall TfServer::ssServerClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        String s=Socket->ReceiveText();
        ShowMessage(s);
       
}
//---------------------------------------------------------------------------
