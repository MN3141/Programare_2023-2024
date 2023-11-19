//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
        TLabel *IText;
        TButton *btnUnu;
        TButton *btnExit;
        TButton *btnEdit;
        TButton *btnConfig;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnUnuClick(TObject *Sender);
        void __fastcall btnEditClick(TObject *Sender);
        void __fastcall btnConfigClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
