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
class TfServer : public TForm
{
__published:	// IDE-managed Components
        TButton *btnExit;
        TMemo *mText;
        TServerSocket *ssServer;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall ssServerClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
        __fastcall TfServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfServer *fServer;
//---------------------------------------------------------------------------
#endif
