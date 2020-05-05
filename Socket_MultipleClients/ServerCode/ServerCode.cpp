// ServerCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include<WinSock2.h>
#include "CSocket.h"

#pragma comment (lib, "ws2_32.lib")

int main()
{
  cout << "Server main started" << endl;

  // Initialize WinSock library
  WSADATA wsaData;

  int wsOk = WSAStartup(0x202, &wsaData);
  if (0 != wsOk)
  {
    cout << "WSAStartup failed" << endl;
    return 0;
  }

  // Create Socket (Server)
  CServerSocket listeningSocket1;

  // Bind the IP address and port to socket.
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(22000);
  addr.sin_addr.S_un.S_addr = INADDR_ANY;

  listeningSocket1.bindSocket((sockaddr *)&addr, sizeof(addr));

  // Tell WinSock that socket is listening
  listeningSocket1.listenSocket(SOMAXCONN);

  // wait for connection
  sockaddr_in client;
  int clientSize = sizeof(client);

  CClientSocket clientSocket1 = listeningSocket1.acceptCSocket((sockaddr *)&client, &clientSize);

  // while loop, accept and echo client message.
  char buff[4096] = "";

  do
  {
    memset(buff, 0, 4096);
    int bytesRecv = clientSocket1.recvData(buff, 4096, 0);
    if (SOCKET_ERROR == bytesRecv || 0 == bytesRecv)
    {
      break;
    }

    cout << "client msg : " << buff << endl;

  } while (buff[0] = '0' || buff[0] == 0);

  // Cleanup WinSock.
  WSACleanup();

  cout << "Server main finished" << endl;
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
