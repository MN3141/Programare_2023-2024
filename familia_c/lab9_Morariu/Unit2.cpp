//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfEdit *fEdit;
//---------------------------------------------------------------------------
__fastcall TfEdit::TfEdit(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfEdit::btnCancelClick(TObject *Sender)
{
        fMain->Show();
        fEdit->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TfEdit::btnOkClick(TObject *Sender)
{
       if( fConfig->cbValidare->Checked==true)
               { fMain->IText->Caption=fEdit->eText->Text;
                fMain->Show();
                fEdit->Close();    }
                else ShowMessage("Trebuie sa validezi!");
}
//---------------------------------------------------------------------------

