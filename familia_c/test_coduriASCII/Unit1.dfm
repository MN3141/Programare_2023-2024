object Form1: TForm1
  Left = 277
  Top = 170
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
  object labelMessage: TLabel
    Left = 168
    Top = 72
    Width = 72
    Height = 13
    Caption = 'CODURI ASCII'
  end
  object labelCode: TLabel
    Left = 160
    Top = 96
    Width = 3
    Height = 13
  end
  object btnOk: TButton
    Left = 104
    Top = 272
    Width = 121
    Height = 65
    Caption = 'OK'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object Memo1: TMemo
    Left = 320
    Top = 120
    Width = 361
    Height = 137
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
