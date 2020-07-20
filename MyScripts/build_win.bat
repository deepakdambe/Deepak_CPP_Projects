
@echo off

cd C:\ccm_wa\git\jci_scripts
SET logDir=C:\ccm_wa\git\logs
set is_Local_PC=1
set notepadPath="C:\Program Files\Notepad++\notepad++.exe"

echo $$$$$$$$$$ All JNC projects started building, plz refer file "logs\winBuilds.log" .... $$$$$$$$$$
echo $$$$$$$$$$ All JNC projects started building .... $$$$$$$$$$ > %logDir%\winBuilds.log

%notepadPath% %logDir%\winBuilds.log

::call jnc-build.bat all build debug NAE-supervisor-family Win32 > %logDir%\winBuilds.log

REM debug, release
set Build_Config=release

REM call .\win32-batch\Win32build.bat   C:\ccm_wa\git\wolfSSL\Private\Win32_Make\ C:\ccm_wa\git\wolfSSL  %Build_Config% C:\ccm_wa\git\jci_scripts\cmake\targets\NAE-supervisor-family.cmake >> %logDir%\winBuilds.log 2>&1

REM Build CURL library
REM call C:\ccm_wa\git\curl\build.bat >> %logDir%\winBuilds.log 2>&1

REM call .\win32-batch\Win32clean.bat   C:\ccm_wa\git\jci_msl\Private\Win32_Make\
call .\win32-batch\Win32build.bat   C:\ccm_wa\git\jci_msl\Private\Win32_Make\ C:\ccm_wa\git\jci_msl  %Build_Config% C:\ccm_wa\git\jci_scripts\cmake\targets\NAE-supervisor-family.cmake >> %logDir%\winBuilds.log 2>&1

echo. >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_base_libs      build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_mms            build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_os_api         build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_ore            build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_baccomm        build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_ore_features   build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_pointio        build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_serial_comm    build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_tool_lib       build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_integrations   build %Build_Config% NAE-supervisor-family Win32 >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
echo. >> %logDir%\winBuilds.log 2>&1



echo. >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_base_libs      build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_mms            build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_os_api         build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_ore            build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_baccomm        build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_ore_features   build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_pointio        build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_serial_comm    build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_tool_lib       build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
call jnc-build.bat jci_integrations   build %Build_Config% NAE-supervisor-family Win32 none Big_OID >> %logDir%\winBuilds.log 2>&1    &&  echo "Build Done" >> %logDir%\winBuilds.log 2>&1
echo. >> %logDir%\winBuilds.log 2>&1



%notepadPath% %logDir%\winBuilds.log

echo $$$$$$$$$$ All JNC projects is builded successfully.... $$$$$$$$$$
timeout /t 5

REM timeout /t 22
REM exit

cd ..
C:\ccm_wa\git\myScripts\BuildProj_G3_10.bat

pause
exit

echo $$$$$$$$$$ All G3 projects is builded successfully.... $$$$$$$$$$
timeout /t 111
exit

