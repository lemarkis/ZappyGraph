#include "SocketInternet.hpp"

SocketInternet::SocketInternet(std::string const & _name) : name(_name)
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		throw my_exception("Error with opening socket");
		exit(-1);
	}
	server.sin_addr.s_addr = htons(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(1025);
}

SocketInternet::~SocketInternet()
{}

void SocketInternet::socketBind() const
{
	if (bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)))
    {
        throw my_exception("Error with Bind");
        exit(1);
    }
}

int SocketInternet::getSock() const
{return sock;}

void SocketInternet::socketListen(int nb) const
{
	listen(sock, nb);
}

int SocketInternet::socketAccept(struct sockaddr_un *client, socklen_t *len) const
{
	return (accept(sock, (struct sockaddr *) client, len));
}

int SocketInternet::socketRead(int fd, std::string &buff)
{
	char test[4096];
	int rd = read(fd, test, 4096);
	test[rd] = 0;
	std::string tmp(test);
	buff = tmp;
	return rd;
}

int SocketInternet::socketRead(std::string &buff)
{
	char test[4096];
	int rd = read(sock, test, 4096);
	test[rd] = 0;
	std::string tmp(test);
	buff = tmp;
	return rd;
}

void SocketInternet::socketClose(int fd) const
{
	close(fd);
}

void SocketInternet::socketClose() const
{
	close(sock);
	unlink(name.c_str());
}

void SocketInternet::socketFD_ZERO(fd_set *arg)
{
	FD_ZERO(arg);
}

void SocketInternet::socketFD_SET(int sockTmp, fd_set *arg)
{
	FD_SET(sockTmp, arg);
}


int SocketInternet::socketSelect(int sockTmp, fd_set *read, fd_set *write) const
{
	return select(sockTmp + 1, read, write, NULL, NULL);
}

int SocketInternet::socketConnect() const
{
    return (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)));
}

int SocketInternet::socketWrite(int fd, std::string const& str) const
{
	return (write(fd, str.c_str(), str.length()));
}

int SocketInternet::socketWrite(std::string const &str) const
{
	return (write(sock, str.c_str(), str.length()));
}