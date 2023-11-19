//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfConfig : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *cbValidare;
        TButton *btnOk;
        TButton *btnCancel;
        void __fastcall btnOkClick(TObject *Sender);
        void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfConfig *fConfig;
//---------------------------------------------------------------------------
#endif
