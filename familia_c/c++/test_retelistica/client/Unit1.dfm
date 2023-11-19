object fClient: TfClient
  Left = 304
  Top = 296
  Width = 870
  Height = 640
  Caption = 'CLIENT'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnExit: TButton
    Left = 200
    Top = 312
    Width = 89
    Height = 49
    Caption = 'EXIT'
    TabOrder = 0
    OnClick = btnExitClick
  end
  object btnSend: TButton
    Left = 384
    Top = 312
    Width = 89
    Height = 41
    Caption = 'EDIT'
    TabOrder = 1
    OnClick = btnSendClick
  end
  object mEdit: TEdit
    Left = 264
    Top = 104
    Width = 161
    Height = 21
    TabOrder = 2
    Text = 'Semigrupa'
  end
  object ClientSocket1: TClientSocket
    Active = True
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 3000
    Left = 72
    Top = 184
  end
end
