//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfConfig *fConfig;
//---------------------------------------------------------------------------
__fastcall TfConfig::TfConfig(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfConfig::btnOkClick(TObject *Sender)
{
        fConfig->Close();
        fMain->Show();

}
//---------------------------------------------------------------------------
void __fastcall TfConfig::btnCancelClick(TObject *Sender)
{
        fConfig->cbValidare->Checked=false;
        fConfig->Close();
        fMain->Show();



}
//---------------------------------------------------------------------------
