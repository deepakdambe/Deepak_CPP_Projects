
@echo off


net session > nul 2>&1
if NOT %errorLevel% == 0 (
  echo Please run this script as admin.
  pause
  exit
)

call :Stop_Services

timeout 5
echo press any to restart services...
pause

echo.
echo " ***** Restarting IIS service *****"
iisreset

REM Try one more time if it fails.
if NOT %errorLevel% == 0 (
  iisreset
)

timeout 5

echo.
echo " ***** Restarting Device Manager service *****"
net start miiidm


timeout 555
net pause miiidm
timeout 55

EXIT /B 0

REM ==================================================  FUNCTIONS  ==================================================

:Stop_Services 

  echo Stopping services...

  REM Killing running services...
  TASKKILL /F /IM DeviceManager*
  TASKKILL /F /IM w3wp*
  TASKKILL /F /IM javaw*

  iisreset /stop

  REM Try one more time if it fails.
  if NOT %errorLevel% == 0 (
    iisreset /stop
  )

  echo All services are stopped...
  timeout 11
EXIT /B 0

