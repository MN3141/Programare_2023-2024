::This is a demo for launching a Flash game using Command Line Interface
::Pre-requisites:
::-add path to Flash player to PATH (you can get it from Bluemaxima's Flashpoint)
::-gather your *.swf files in a directory

@echo off

set GAME_PATH = %cd%\game.swf
flashplayer_32_sa %GAME_PATH%