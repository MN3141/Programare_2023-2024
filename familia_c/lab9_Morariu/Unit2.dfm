object fEdit: TfEdit
  Left = 247
  Top = 365
  Width = 1044
  Height = 540
  Caption = 'Fereastra editare'
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnOk: TButton
    Left = 224
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = btnOkClick
  end
  object btnCancel: TButton
    Left = 640
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object eText: TEdit
    Left = 360
    Top = 104
    Width = 225
    Height = 21
    TabOrder = 2
  end
end
