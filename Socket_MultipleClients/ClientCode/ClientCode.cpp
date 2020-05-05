// ClientCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#include<WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#pragma warning(disable : 4996)

int main()
{
  cout << "Client main started" << endl;

  WSADATA wsaData;

  int wsOk = WSAStartup(0x202, &wsaData);
  if (0 != wsOk)
  {
    cout << "WSAStartup failed" << endl;
    return 0;
  }

  const int port = 22000;
  const char server_name[22] = "localhost";
  //const char server_name[22] = "127.0.0.1";

  struct hostent *hp;

  // Attempt to detect if we should call gethostbyname() or gethostbyaddr()
  if (isalpha(server_name[0]))
  {   // server address is a name
    hp = gethostbyname(server_name);
  }
  else
  { // Convert nnn.nnn address to a usable one
    unsigned int addr = inet_addr(server_name);
    hp = gethostbyaddr((char *)&addr, 4, AF_INET);
  }

  // Copy the resolved information into the sockaddr_in structure
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  memcpy(&(server.sin_addr), hp->h_addr, hp->h_length);
  server.sin_family = hp->h_addrtype;
  server.sin_port = htons(port);

  SOCKET  conn_socket = socket(AF_INET, SOCK_STREAM, 0); /* Open a socket */

  cout <<"Client: Client connecting to "<< hp->h_name << endl;

  if (connect(conn_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
  {
    fprintf(stderr, "Client: connect() failed: %d\n", WSAGetLastError());
    WSACleanup();
    return -1;
  }
  else
    printf("Client: connect() is OK.\n");

  string userInput;
  do {
    std::cout << "Please enter the string to send to server .. . \n";
    std::getline(std::cin, userInput);
    auto bytesSent = send(conn_socket, userInput.c_str(), userInput.size() + 1, 0);
    if (SOCKET_ERROR == bytesSent || 0 == bytesSent)
    {
      std::cout << "Error in sending data to server \n";
      WSACleanup();
      return WSAGetLastError();
    }
  } while (userInput.size() > 0); // || 0 == userInput[0] || '0' == userInput[0]

  cout << "Client main finished" << endl;
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
