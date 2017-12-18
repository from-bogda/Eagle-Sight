//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <IniFiles.hpp>
#include "Unit2.h"

#include "Model.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 TIniFile* ini = new TIniFile (GetCurrentDir() + "//settings.ini");
        Left = ini->ReadInteger("MainWindow", "Left", 0);
        Top = ini->ReadInteger("MainWindow", "Top", 0);
        Top = ini->ReadInteger("MainWindow", "Top", 0);
        delete ini;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  TIniFile* ini = new TIniFile (GetCurrentDir() + "//settings.ini");
        ini->WriteInteger("MainWindow", "Left", Left);
        ini->WriteInteger("MainWindow", "Top", Top);
        delete ini;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Form2->Show();
        Timer1->Enabled=false;
        Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
        Timer1->Interval=(ComboBox1->Text)*1000;
        Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        Image1->Visible=false;
        Form2->Close();
        Timer2->Enabled=false;
}
//---------------------------------------------------------------------------

