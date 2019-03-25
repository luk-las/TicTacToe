//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <time.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        TImage *pola[9];
        TImage *turaWsk;
        char p[9];
        char kto;
        bool poleZajete;
        bool zaczynaKolko = true;
        bool graRozpoczeta = false;
        TRadioButton *RBkolegaWsk, *RBlatwyWsk, *RBtrudnyWsk;
        TRadioButton *wybor;
        int los;
        bool koniec;

        void sprawdz()
        {
                char *tekst;
                if     ((p[0]==p[1] && p[1]==p[2] && p[0]!='n') ||
                        (p[3]==p[4] && p[4]==p[5] && p[3]!='n') ||
                        (p[6]==p[7] && p[7]==p[8] && p[6]!='n') ||
                        (p[0]==p[3] && p[3]==p[6] && p[0]!='n') ||
                        (p[1]==p[4] && p[4]==p[7] && p[1]!='n') ||
                        (p[2]==p[5] && p[5]==p[8] && p[2]!='n') ||
                        (p[0]==p[4] && p[4]==p[8] && p[0]!='n') ||
                        (p[2]==p[4] && p[4]==p[6] && p[2]!='n'))
                {
                        
                        if(kto=='x')    tekst = "Wygrywa kó³ko!";
                        else            tekst = "Wygrywa krzy¿yk!";
                        Application->MessageBox(tekst, "Koniec gry", MB_OK);
                        for(int i=0; i<9; i++)
                                if(p[i]=='n')
                                        pola[i]->Enabled=false;
                        koniec = true;
                }
                else if(p[0]!='n' && p[1]!='n' && p[2]!='n' &&
                        p[3]!='n' && p[4]!='n' && p[5]!='n' &&
                        p[6]!='n' && p[7]!='n' && p[8]!='n')
                {
                        tekst = "Remis";
                        Application->MessageBox(tekst, "Koniec gry", MB_OK);
                        koniec = true;
                }

        }

        void pokaz(int i)
        {
           if(!poleZajete)
                {
                        switch(kto)
                        {
                                case 'o':
                                pola[i]->Picture->LoadFromFile("img/O.bmp");
                                break;
                                case 'x':
                                pola[i]->Picture->LoadFromFile("img/X.bmp");
                                break;
                        }
                        poleZajete = true;
                }
        }

        void dajWybor()
        {
            if(RBkolegaWsk->Checked==true) wybor = RBkolegaWsk;
            if(RBlatwyWsk->Checked==true)  wybor = RBlatwyWsk;
            if(RBtrudnyWsk->Checked==true) wybor = RBtrudnyWsk;
        }

        void ustawO(int i)
        {
                pola[i]->Picture->LoadFromFile("img/O.bmp");
                p[i]='o';
                kto='x';
                turaWsk->Picture->LoadFromFile("img/Xsmall.bmp");
                pola[i]->Enabled=false;
                sprawdz();
        }

        void ustawX(int i)
        {
                pola[i]->Picture->LoadFromFile("img/X.bmp");
                p[i]='x';
                kto='o';
                turaWsk->Picture->LoadFromFile("img/Osmall.bmp");
                pola[i]->Enabled=false;
                sprawdz();
        }


        void wstaw(int i)
        {
        if(wybor == RBkolegaWsk)
        {
                RBkolegaWsk->Checked=true;
                if(p[i]=='n')
                {
                        if(kto=='o')    ustawO(i);
                        else            ustawX(i);
                }
        }
        else if(wybor == RBlatwyWsk)
        {
                RBlatwyWsk->Checked=true;
                if(p[i]=='n')
                {
                        if(kto=='o')
                        {
                                ustawO(i);
                                if(!koniec)
                                {
                                        while(p[los]!='n')
                                                los = rand()%9;
                                        ustawX(los);
                                }
                        }
                        else
                                ustawX(los);
                }
        }
        else if(wybor == RBtrudnyWsk)
        {
                RBtrudnyWsk->Checked=true;
                if(p[i]=='n')
                {
                        if(kto=='o')
                        {
                                ustawO(i);
                                if(!koniec)
                                {
                                        if(p[4]=='n')   ustawX(4);
                                        else if(p[0]=='x' && p[1]==p[0]  && p[2]=='n') ustawX(2);
                                        else if(p[0]=='x' && p[2]==p[0]  && p[1]=='n') ustawX(1);
                                        else if(p[1]=='x' && p[2]==p[1]  && p[0]=='n') ustawX(0);
                                        else if(p[3]=='x' && p[4]==p[3]  && p[5]=='n') ustawX(5);
                                        else if(p[3]=='x' && p[5]==p[3]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='x' && p[5]==p[4]  && p[3]=='n') ustawX(3);
                                        else if(p[6]=='x' && p[7]==p[6]  && p[8]=='n') ustawX(8);
                                        else if(p[6]=='x' && p[8]==p[6]  && p[7]=='n') ustawX(7);
                                        else if(p[7]=='x' && p[8]==p[7]  && p[6]=='n') ustawX(6);
                                        else if(p[0]=='x' && p[3]==p[0]  && p[6]=='n') ustawX(6);
                                        else if(p[0]=='x' && p[6]==p[0]  && p[3]=='n') ustawX(3);
                                        else if(p[3]=='x' && p[6]==p[3]  && p[0]=='n') ustawX(0);
                                        else if(p[1]=='x' && p[4]==p[1]  && p[7]=='n') ustawX(7);
                                        else if(p[4]=='x' && p[1]==p[4]  && p[7]=='n') ustawX(7);
                                        else if(p[4]=='x' && p[7]==p[4]  && p[1]=='n') ustawX(1);
                                        else if(p[2]=='x' && p[5]==p[2]  && p[8]=='n') ustawX(8);
                                        else if(p[2]=='x' && p[8]==p[2]  && p[5]=='n') ustawX(5);
                                        else if(p[5]=='x' && p[8]==p[5]  && p[2]=='n') ustawX(2);
                                        else if(p[0]=='x' && p[4]==p[0]  && p[8]=='n') ustawX(8);
                                        else if(p[0]=='x' && p[8]==p[0]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='x' && p[8]==p[4]  && p[0]=='n') ustawX(0);
                                        else if(p[2]=='x' && p[4]==p[2]  && p[6]=='n') ustawX(6);
                                        else if(p[2]=='x' && p[6]==p[2]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='x' && p[6]==p[4]  && p[2]=='n') ustawX(2);
                                        else if(p[0]=='o' && p[1]==p[0]  && p[2]=='n') ustawX(2);
                                        else if(p[0]=='o' && p[2]==p[0]  && p[1]=='n') ustawX(1);
                                        else if(p[1]=='o' && p[2]==p[1]  && p[0]=='n') ustawX(0);
                                        else if(p[3]=='o' && p[4]==p[3]  && p[5]=='n') ustawX(5);
                                        else if(p[3]=='o' && p[5]==p[3]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='o' && p[5]==p[4]  && p[3]=='n') ustawX(3);
                                        else if(p[6]=='o' && p[7]==p[6]  && p[8]=='n') ustawX(8);
                                        else if(p[6]=='o' && p[8]==p[6]  && p[7]=='n') ustawX(7);
                                        else if(p[7]=='o' && p[8]==p[7]  && p[6]=='n') ustawX(6);
                                        else if(p[0]=='o' && p[3]==p[0]  && p[6]=='n') ustawX(6);
                                        else if(p[0]=='o' && p[6]==p[0]  && p[3]=='n') ustawX(3);
                                        else if(p[3]=='o' && p[6]==p[3]  && p[0]=='n') ustawX(0);
                                        else if(p[1]=='o' && p[4]==p[1]  && p[7]=='n') ustawX(7);
                                        else if(p[4]=='o' && p[1]==p[4]  && p[7]=='n') ustawX(7);
                                        else if(p[4]=='o' && p[7]==p[4]  && p[1]=='n') ustawX(1);
                                        else if(p[2]=='o' && p[5]==p[2]  && p[8]=='n') ustawX(8);
                                        else if(p[2]=='o' && p[8]==p[2]  && p[5]=='n') ustawX(5);
                                        else if(p[5]=='o' && p[8]==p[5]  && p[2]=='n') ustawX(2);
                                        else if(p[0]=='o' && p[4]==p[0]  && p[8]=='n') ustawX(8);
                                        else if(p[0]=='o' && p[8]==p[0]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='o' && p[8]==p[4]  && p[0]=='n') ustawX(0);
                                        else if(p[2]=='o' && p[4]==p[2]  && p[6]=='n') ustawX(6);
                                        else if(p[2]=='o' && p[6]==p[2]  && p[4]=='n') ustawX(4);
                                        else if(p[4]=='o' && p[6]==p[4]  && p[2]=='n') ustawX(2);

                                        else
                                        {       if(p[0]=='o' && p[8]=='o' || p[2]=='o' && p[6]=='o')
                                                {
                                                        while(p[los]!='n' || (los==0 && los==2 && los==6 && los==8))
                                                                        los = rand()%9;
                                                        ustawX(los);
                                                }
                                                else if(p[0]=='n' || p[2]=='n' || p[6]=='n' || p[8]=='n')
                                                {
                                                        while(p[los]!='n' || (los!=0 && los!=2 && los!=6 && los!=8))
                                                                        los = rand()%9;
                                                        ustawX(los);
                                                }
                                                else
                                                {       while(p[los]!='n')
                                                                los = rand()%9;
                                                        ustawX(los);
                                                }
                                        }
                                }
                        }
                        else
                                ustawX(i);
                }
        }
        }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

        pola[0] = pole0;
        pola[1] = pole1;
        pola[2] = pole2;
        pola[3] = pole3;
        pola[4] = pole4;
        pola[5] = pole5;
        pola[6] = pole6;
        pola[7] = pole7;
        pola[8] = pole8;
        turaWsk = tura;
        RBkolegaWsk = RBkolega;
        RBlatwyWsk = RBlatwy;
        RBtrudnyWsk = RBtrudny;
        srand(time(NULL));
        los = rand()%9;
        koniec = false;

        for(int i=0; i<9; i++)
        {
            pola[i]->Picture->LoadFromFile("img/N.bmp");
            pola[i]->Enabled=false;
            p[i]='n';
        }      

        if(zaczynaKolko)
        {
          kto = 'o';
          tura->Picture->LoadFromFile("img/Osmall.bmp");
          zaczynaKolko = false;
        }
        else
        {
         kto = 'x';
         tura->Picture->LoadFromFile("img/Xsmall.bmp");
         zaczynaKolko = true;
        }

        poleZajete = false;

        if(!graRozpoczeta)      RBkolegaWsk->Checked=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole0Click(TObject *Sender)
{
        wstaw(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole1Click(TObject *Sender)
{
        wstaw(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole2Click(TObject *Sender)
{
        wstaw(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole3Click(TObject *Sender)
{
        wstaw(3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole4Click(TObject *Sender)
{
        wstaw(4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole5Click(TObject *Sender)
{
        wstaw(5);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole6Click(TObject *Sender)
{
        wstaw(6);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole7Click(TObject *Sender)
{
        wstaw(7);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole8Click(TObject *Sender)
{
        wstaw(8);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole0MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole4MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole5MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole6MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole7MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pole8MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        pokaz(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(poleZajete)
          for(int i=0; i<9; i++)
                if(pola[i]->Enabled==true)
                        pola[i]->Picture->LoadFromFile("img/N.bmp");
        poleZajete = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(!graRozpoczeta)
        {
            graRozpoczeta = true;
            Button1->Caption="OD NOWA";
            dajWybor();
        }
        else
        {
            TForm1::FormCreate(Sender);
            dajWybor();
        }

        for(int i=0; i<9; i++)  pola[i]->Enabled=true;
        if(kto=='x' && wybor==RBlatwyWsk)  wstaw(los);
        else if(kto=='x' && wybor==RBtrudnyWsk)
        {
                if(los==0 || los==2 || los==6 || los==8)
                        wstaw(los);
                else
                        wstaw(4);
        }

}
//---------------------------------------------------------------------------


