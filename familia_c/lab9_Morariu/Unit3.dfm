object fConfig: TfConfig
  Left = 380
  Top = 148
  Width = 1044
  Height = 540
  Caption = 'Fereastra configurare'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object cbValidare: TCheckBox
    Left = 408
    Top = 112
    Width = 65
    Height = 41
    Caption = 'Validare'
    TabOrder = 0
  end
  object btnOk: TButton
    Left = 216
    Top = 256
    Width = 65
    Height = 57
    Caption = 'Ok'
    TabOrder = 1
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 592
    Top = 256
    Width = 65
    Height = 65
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnCancelClick
  end
end
