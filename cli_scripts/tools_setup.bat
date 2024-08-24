::This is a demo script used for setting up some tools
::and testing Github Actions

::This script requires at least Windows 10
set TOOLS_PATH=E:\tools
set TEMP_DIR=temp
mkdir %TOOLS_PATH%

mkdri %TOOLS_PATH%
mkdir temp
mkdir temp\notepad

curl -L https://github.com/notepad-plus-plus/notepad-plus-plus/releases/download/v8.6.8/npp.8.6.8.portable.x64.zip --ssl-revoke-best-effort --output %TEMP_DIR%\npp.zip
winrar x -df temp\npp.zip %cd%\temp\notepad

curl -L https://mh-nexus.de/en/downloads.php?product=HxD20#HxDSetup_zip-signatures-popup --ssl-revoke-best-effort --output %TOOLS_PATH%\hxd.zip

move %cd%\temp\notepad %TOOLS_PATH%
rmdir /s /q temp
