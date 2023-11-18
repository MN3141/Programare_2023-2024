@echo off
set folder=test
cd %folder%

if "%1" == "" goto :all
if "%1" == "c" goto :label
if "%1" == "d" goto :debug

:all
    cd %folder%
    ..\tasm.exe /zi/la cod.asm
    ..\tlink /v cod.obj
    ..\td cod.exe
    goto :eof

:label
    cd %folder%
    ..\tasm.exe /zi/la cod.asm
    cls
    ....\tlink /v cod.obj
    cls
    cod.exe
    goto :eof
:debug
    cd %folder%
    cls
    ..\tasm.exe /zi/la cod.asm
    goto :eof

:eof 
    cd ../