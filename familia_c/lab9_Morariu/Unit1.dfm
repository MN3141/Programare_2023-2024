object fMain: TfMain
  Left = 399
  Top = 163
  Width = 1044
  Height = 540
  Caption = 'Fereastra principala'
  Color = clActiveBorder
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object IText: TLabel
    Left = 440
    Top = 96
    Width = 73
    Height = 41
    Caption = 'Semigrupa'
    Color = clAqua
    ParentColor = False
  end
  object btnUnu: TButton
    Left = 208
    Top = 208
    Width = 121
    Height = 73
    Caption = 'Unu'
    TabOrder = 0
    OnClick = btnUnuClick
  end
  object btnExit: TButton
    Left = 200
    Top = 312
    Width = 137
    Height = 73
    Caption = 'Exit'
    TabOrder = 1
    OnClick = btnExitClick
  end
  object btnEdit: TButton
    Left = 672
    Top = 200
    Width = 121
    Height = 73
    Caption = 'Editare'
    TabOrder = 2
    OnClick = btnEditClick
  end
  object btnConfig: TButton
    Left = 672
    Top = 304
    Width = 121
    Height = 73
    Caption = 'Configurare'
    TabOrder = 3
    OnClick = btnConfigClick
  end
end
