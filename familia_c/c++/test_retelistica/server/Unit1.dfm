object fServer: TfServer
  Left = 358
  Top = 252
  Width = 870
  Height = 640
  Caption = 'SERVER'
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
    Left = 328
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 0
    OnClick = btnExitClick
  end
  object mText: TMemo
    Left = 216
    Top = 72
    Width = 377
    Height = 169
    Lines.Strings = (
      'mText')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object ssServer: TServerSocket
    Active = True
    Port = 3000
    ServerType = stNonBlocking
    OnClientRead = ssServerClientRead
    Left = 96
    Top = 344
  end
end
