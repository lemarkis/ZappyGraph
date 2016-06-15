#ifndef SOCKETINTERNET_HPP_
#define SOCKETINTERNET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/un.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>

class SocketInternet
{
protected:
	int sock;
	struct sockaddr_in server;
	std::string const name;

public:
	SocketInternet(std::string const &);
	~SocketInternet();

	virtual void socketBind() const;
	virtual void socketListen(int nb) const;
	virtual int socketAccept(struct sockaddr_un *, socklen_t *len) const;
	virtual int socketRead(int, std::string &);
	virtual int socketRead(std::string &);
	virtual void socketClose(int) const;
	virtual void socketClose() const;
	virtual int socketConnect() const;
	virtual int socketWrite(int fd, std::string const& str) const;
	virtual int socketWrite(std::string const&) const;
	virtual int socketSelect(int sockTmp, fd_set *read, fd_set *write) const;
	virtual void socketFD_ZERO(fd_set *arg);
	virtual void socketFD_SET(int sockTmp, fd_set *arg);
	virtual int getSock() const;

};

#endif