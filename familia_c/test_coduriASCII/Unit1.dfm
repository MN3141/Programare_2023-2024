object Form1: TForm1
  Left = 244
  Top = 101
  Width = 1044
  Height = 540
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object codeLabel: TLabel
    Left = 264
    Top = 80
    Width = 50
    Height = 13
    Caption = 'codeLabel'
  end
  object label: TLabel
    Left = 256
    Top = 48
    Width = 185
    Height = 13
    Caption = 'Codurile ASCII ale simbolurilor introduse'
  end
  object inputEdit: TEdit
    Left = 336
    Top = 232
    Width = 265
    Height = 21
    TabOrder = 0
    Text = 'inputEdit'
  end
  object okButton: TButton
    Left = 160
    Top = 352
    Width = 153
    Height = 57
    Caption = 'OK'
    TabOrder = 1
    OnClick = okButtonClick
  end
end
