#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#ifdef _WIN32

#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include <io.h>
#include <Windows.h>

#else

#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/select.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#endif

#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>

#include "MyException.hpp"

class Socket
{
protected:
	int sock;
	struct sockaddr_in server;
	std::string const name;
	struct timeval tv;

public:
	Socket(std::string const &, int);
	~Socket();

	void socketBind() const;
	void socketListen(int nb) const;
	int socketAccept() const;
	int socketRead(int, std::string &, size_t const size = 4096);
	int socketRead(std::string &, size_t const size = 4096);
	void socketClose(int) const;
	void socketClose();
	void socketConnect() const;
	int socketWrite(int fd, std::string const& str) const;
	int socketWrite(std::string const&) const;
	void socketSelect(int sockTmp, fd_set *read, fd_set *write) const;
	void socketSelect(fd_set *read, fd_set *write) const;
	void socketFD_ZERO(fd_set *arg);
	void socketFD_SET(int sockTmp, fd_set *arg);
	void socketFD_SET(fd_set *arg);
	int getSock() const;

};

#endif