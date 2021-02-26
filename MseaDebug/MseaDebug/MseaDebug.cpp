// MseaDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <Windows.h>

#include "C:\ccm_wa\git\jci_base_libs\Public\Includes\productFamilyVariations.h"
#include "C:\ccm_wa\git\g3_metasys_core\g3_product_shared\N40_N50\target\nxx_build\MetasysControlEngine.h"
#include "C:\ccm_wa\git\g3_base\Public\includes\covmonitormain.h"

#ifdef WIN32
#include "C:\ccm_wa\myCodes\Deepak_CPP_Projects\myLogs\myLogs.h"
#else
#include "/mnt/c/ccm_wa/myCodes/Deepak_CPP_Projects/myLogs/myLogs.h"
#endif

#pragma message("$$$$$ This is test message $$$$$")

// Define required macros
#define UNSIGNED16             unsigned short

// __declspec(dllimport)
// Explicitly declare functions...
//UNSIGNED16 verifyNoConfigEdit(const TCHAR * config_pathname);


//C:\ccm_wa\git\g3_metasys_core\g3_product_nis\Win32_Release\MSEA_Supv.lib

void fun()
{

  cin.get();
  exit(0);
}

int main()
{
  //fun();

  cout << "Main started v1.1" << endl;
  logMessage("=====================================================================================");

  cout << "Verifying whether we can load MSEA_Supv.dll..." << endl;
  HMODULE hModule = LoadLibraryEx(TEXT("MSEA_Supv.dll"), NULL, 0);
  if (hModule == NULL)
  {
    cout << "Unable to load DLL, Error : " << GetLastError() << endl;
    cin.get();
    return 0;
  }
  cout << "DLL loaded successfully...\n" << endl;

  cout << "Calling fnMCEStartup..." << endl;
  fnMCEStartup();
  cout << "fnMCEStartup Finished...\n" << endl;

  //Sleep(5555);
  //cout << "Calling startADXOnlyDataRefresh, Press any key to continue..." << endl;
  //cin.get();
  //startADXOnlyDataRefresh();


  //Sleep(2222);
  //cout << "Calling fnCreateObject, Press any key to continue..." << endl;
  ////cin.get();
  //LPTSTR *FailedObject = NULL;
  //long FailedProperty;
  //long FailedIndex;
  //long status;
  //const TCHAR *xml = LR"(<objects xmlns="http://johnsoncontrols.com/MetasysIII/2002/3/Core" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"> <object classid="806" bacnetclassid="806" classVersion="2.0" ref="DeepWin10VM:DeepWin10VM/Generic 1"> <property id="28"> <data> <string xsi:nil="1" /> </data> </property> <property id="79"> <data> <enum>806</enum> </data> </property> <property id="796"> <data> <unsignedShort>1</unsignedShort> </data> </property> <property id="908"> <data> <enum set="33">5</enum> </data> </property> <property id="2390"> <data> <string>Generic 1</string> </data> </property> <property id="3060"> <data> <enum set="1766">0</enum> </data> </property> <property id="6049"> <data> <listof /> </data> </property> <property id="32527"> <data> <string>DeepWin10VM:DeepWin10VM/Generic 1</string> </data> </property> <property id="32581"> <data> <listof /> </data> </property> </object> <object classid="806" bacnetclassid="806" classVersion="2.0" ref="DeepWin10VM:DeepWin10VM/Generic 1.Building 1"> <property id="28"> <data> <string xsi:nil="1" /> </data> </property> <property id="79"> <data> <enum>806</enum> </data> </property> <property id="796"> <data> <unsignedShort>1</unsignedShort> </data> </property> <property id="908"> <data> <enum set="33">5</enum> </data> </property> <property id="2390"> <data> <string>Building 1</string> </data> </property> <property id="3060"> <data> <enum set="1766">1</enum> </data> </property> <property id="6049"> <data> <listof /> </data> </property> <property id="32527"> <data> <string>DeepWin10VM:DeepWin10VM/Generic 1.Building 1</string> </data> </property> <property id="32581"> <data> <listof /> </data> </property> </object> <object classid="806" bacnetclassid="806" classVersion="2.0" ref="DeepWin10VM:DeepWin10VM/Generic 1.Building 1.Floor 1"> <property id="28"> <data> <string xsi:nil="1" /> </data> </property> <property id="79"> <data> <enum>806</enum> </data> </property> <property id="796"> <data> <unsignedShort>1</unsignedShort> </data> </property> <property id="908"> <data> <enum set="33">5</enum> </data> </property> <property id="2390"> <data> <string>Floor 1</string> </data> </property> <property id="3060"> <data> <enum set="1766">2</enum> </data> </property> <property id="6049"> <data> <listof /> </data> </property> <property id="32527"> <data> <string>DeepWin10VM:DeepWin10VM/Generic 1.Building 1.Floor 1</string> </data> </property> <property id="32581"> <data> <listof /> </data> </property> </object> <object classid="806" bacnetclassid="806" classVersion="2.0" ref="DeepWin10VM:DeepWin10VM/Generic 1.Building 1.Floor 1.Room 1"> <property id="28"> <data> <string xsi:nil="1" /> </data> </property> <property id="79"> <data> <enum>806</enum> </data> </property> <property id="796"> <data> <unsignedShort>1</unsignedShort> </data> </property> <property id="908"> <data> <enum set="33">5</enum> </data> </property> <property id="2390"> <data> <string>Room 1</string> </data> </property> <property id="3060"> <data> <enum set="1766">3</enum> </data> </property> <property id="6049"> <data> <listof /> </data> </property> <property id="32527"> <data> <string>DeepWin10VM:DeepWin10VM/Generic 1.Building 1.Floor 1.Room 1</string> </data> </property> <property id="32581"> <data> <listof /> </data> </property> </object> </objects>)";
  //long ret = fnCreateObject(xml, FailedObject, &FailedProperty, &FailedIndex, &status, L"", L"", L"", L"");
  //cout << "fnCreateObject Finished, returned : "<< ret << " , status " << status << endl;



  logMessage("=====================================================================================");
  cout << "Main finished" << endl;
  cin.get();
  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
