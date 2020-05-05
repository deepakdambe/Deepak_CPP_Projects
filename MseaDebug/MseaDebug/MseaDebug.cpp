// MseaDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <Windows.h>

#include "C:\ccm_wa\git\jci_base_libs\Public\Includes\productFamilyVariations.h"
#include "C:\ccm_wa\git\g3_metasys_core\g3_product_shared\N40_N50\target\nxx_build\MetasysControlEngine.h"

#ifdef WIN32
#include "C:\ccm_wa\git\myScripts\myLogs.h"
#else
#include "/mnt/c/ccm_wa/git/myScripts/myLogs.h"
#endif


int main()
{
  cout << "Main started" << endl;
  logMessage("");

  // Called any MSEA function here.
  fnMCEStartup();




  logMessage("");
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
