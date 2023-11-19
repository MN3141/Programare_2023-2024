//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TfClient : public TForm
{
__published:	// IDE-managed Components
        TButton *btnExit;
        TButton *btnSend;
        TEdit *mEdit;
        TClientSocket *ClientSocket1;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnSendClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfClient(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfClient *fClient;
//---------------------------------------------------------------------------
#endif
