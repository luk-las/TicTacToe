//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *pole6;
        TImage *pole3;
        TImage *pole2;
        TImage *pole0;
        TImage *pole4;
        TImage *pole5;
        TImage *pole8;
        TImage *pole7;
        TImage *pole1;
        TLabel *Label1;
        TImage *tura;
        TButton *Button1;
        TRadioGroup *RadioGroup1;
        TRadioButton *RBkolega;
        TRadioButton *RBlatwy;
        TRadioButton *RBtrudny;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall pole0Click(TObject *Sender);
        void __fastcall pole1Click(TObject *Sender);
        void __fastcall pole2Click(TObject *Sender);
        void __fastcall pole3Click(TObject *Sender);
        void __fastcall pole4Click(TObject *Sender);
        void __fastcall pole5Click(TObject *Sender);
        void __fastcall pole6Click(TObject *Sender);
        void __fastcall pole7Click(TObject *Sender);
        void __fastcall pole8Click(TObject *Sender);
        void __fastcall pole0MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole4MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole5MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole6MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole7MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall pole8MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
