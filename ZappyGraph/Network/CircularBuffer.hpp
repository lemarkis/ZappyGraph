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
	std::string const getLine();
	int getSize() const;
	int getMaxSize() const;
	int getEmptySize() const;
	bool isFull() const;

private:
	char *buffer;
	int size;
	int start;
	int end;
	std::string const getLine(std::string beginStr);
};

#endif // !CIRCULARBUFFER_HPP
