// MseaDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <Windows.h>

#include "C:\ccm_wa\git\jci_base_libs\Public\Includes\productFamilyVariations.h"
#include "C:\ccm_wa\git\g3_metasys_core\g3_product_shared\N40_N50\target\nxx_build\MetasysControlEngine.h"
#include "C:\ccm_wa\git\g3_base\Public\includes\covmonitormain.h"

#ifdef WIN32
#include "C:\ccm_wa\git\myScripts\myLogs.h"
#else
#include "/mnt/c/ccm_wa/git/myScripts/myLogs.h"
#endif

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

  cout << "Main started v1.7" << endl;
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

  //Sleep(5555);
  //cout << "Calling fnGetNavView, Press any key to continue..." << endl;
  //cin.get();
  //TCHAR *xml = new TCHAR[5555];
  //long ret = fnGetNavView(L"", 52, 0, 0, -1, L"", &xml);
  //cout << "fnGetNavView Finished, returned : "<< ret << endl;



  logMessage("=====================================================================================");
  cout << "Main finished" << endl;
  cin.get();
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
