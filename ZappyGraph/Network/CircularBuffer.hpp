#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#include <string>

class CircularBuffer
{
public:
	CircularBuffer(size_t buffSize);
	~CircularBuffer();

	void putInBuffer(std::string rawStr);
	//std::string getString(size_t lenght);
	std::string getLine();

private:
	char *buffer;
	int size;
	int start;
	int end;
};

#endif // !CIRCULARBUFFER_HPP
