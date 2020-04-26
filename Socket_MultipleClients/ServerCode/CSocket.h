#pragma once

#if _WIN32
  #include<WinSock2.h>
#endif // _WIN32

class CSocket
{
public:
  CSocket(int af = AF_INET, int type = SOCK_STREAM, int protocol = 0);
  virtual ~CSocket();

protected:
  SOCKET m_socket;
};

CSocket::CSocket(int af, int type, int protocol)
{
  m_socket = socket(af, type, protocol);
}

CSocket::~CSocket()
{
  cout << "calling CSocket DEST" << endl;
  closesocket(m_socket);
}

class CServerSocket : public CSocket
{
public:
  CServerSocket(int af = AF_INET, int type = SOCK_STREAM, int protocol = 0) : CSocket(af, type, protocol) {}
  //~CServerSocket();
  int bindSocket(const struct sockaddr * name, int namelen)
  {
    return bind(m_socket, name, namelen);
  }

  int listenSocket(int backlog)
  {
    return listen(m_socket, backlog);
  }

private:

};


