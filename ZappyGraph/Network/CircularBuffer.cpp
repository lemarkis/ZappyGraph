#include "CircularBuffer.hpp"

CircularBuffer::CircularBuffer(size_t buffSize)
{
	buffer = new char(buffSize);
	for (size_t i = 0; i < buffSize; ++i)
	{
		buffer[i] = 0;
	}
	size = buffSize;
	start = 0;
	end = 0;
}

CircularBuffer::~CircularBuffer()
{
	delete buffer;
}

void CircularBuffer::putInBuffer(std::string rawStr)
{

}

std::string CircularBuffer::getLine()
{
	return std::string();
}
