#include "Socket.hpp"

Socket::Socket(std::string const & _ip, int port)
{
	struct protoent *proto;

#ifdef _WIN32
	WSADATA wsaData;
	int iResult;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		throw my_exception("WSAStartup failed\n");
	}
#endif
	tv.tv_sec = 0;
	tv.tv_usec = 10;
	if ((proto = getprotobyname("TCP")) == NULL)
		throw my_exception("Error with opening socket");
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (sock < 0)
		throw my_exception("Error with opening socket");
	server.sin_addr.s_addr = inet_addr(_ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
}

Socket::~Socket()
{
	std::cout << "Class Socket detruite" << std::endl;
	WSACleanup();
}

void Socket::socketBind() const
{
	if (bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_in)))
        throw my_exception("Error with Bind");
}

int Socket::getSock() const
{return sock;}

void Socket::socketListen(int nb) const
{
	if (listen(sock, nb) == -1)
		throw my_exception("Error with Listen");
}

int Socket::socketAccept() const
{
	int fd;
	struct sockaddr_in client;
	int len;

	len = sizeof(client);
	if ((fd = accept(sock, (struct sockaddr *) &client, &len)) == -1)
		throw my_exception("Error with accept");
	return fd;
}

int Socket::socketRead(int fd, std::string &buff, size_t const size)
{
	char * test = new char[size];
	memset(test, 0, size);	
	int rd = recv(fd, test, size - 1, 0);
	if (rd <= 0)
		return -1;
	test[rd] = 0;
	buff = test;
	delete test;
	return rd;
}

int Socket::socketRead(std::string &buff, size_t const size)
{
	char * test = new char[size];
	memset(test, 0, size);
	int rd = recv(sock, test, size - 1, 0);
	if (rd <= 0)
		return -1;
	test[rd] = 0;
	buff = test;
	delete test;
	return rd;
}

void Socket::socketClose(int fd) const
{
#ifdef _WIN32
	closesocket(fd);
#else
	close(fd);
#endif
}

void Socket::socketClose()
{
#ifdef _WIN32
	closesocket(sock);
#else
	close(sock);
#endif
}

void Socket::socketFD_ZERO(fd_set *arg)
{
	FD_ZERO(arg);
}

void Socket::socketFD_SET(int sockTmp, fd_set *arg)
{
	FD_SET(sockTmp, arg);
}

void Socket::socketFD_SET(fd_set * arg)
{
	FD_SET(sock, arg);
}

void Socket::socketSelect(int sockTmp, fd_set *read, fd_set *write) const
{
	if (select(sockTmp + 1, read, write, NULL, &tv) == -1)
		throw my_exception("Error with select");
	return ;
}

void Socket::socketSelect(fd_set *read, fd_set * write) const
{
	if (select(sock + 1, read, write, NULL, &tv) == -1)
		throw my_exception("Error with select");
	return;
}

void Socket::socketConnect() const
{
	if ((connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_in))) < 0)
		throw my_exception("Error with connect");
}

int Socket::socketWrite(int fd, std::string const& str) const
{
	return send(fd, str.c_str(), str.length(), 0);
}

int Socket::socketWrite(std::string const &str) const
{
	return send(sock, str.c_str(), str.length(), 0);
}