#include "CircularBuffer.hpp"

//declare un buffer circulaire de taille buffSize
CircularBuffer::CircularBuffer(size_t buffSize)
{
	buffer = new char[buffSize];
	memset(buffer, 0, buffSize);
	size = buffSize;
	start = 0;
	end = 0;
}

CircularBuffer::~CircularBuffer()
{
	delete buffer;
}

//rempli le buffer avec la string, ecrase le debut de la string si plusieurs tour (methode recursive)
void CircularBuffer::putInBuffer(std::string rawStr)
{
	int i = end;
	int j = 0;
	while (i < size && j < rawStr.size())
	{
		buffer[i] = rawStr.at(j);
		++i;
		++j;
		if (i == start)
			++start;
	}
	end = i - 1;
	if (j < rawStr.size())
	{
		end = 0;
		putInBuffer(rawStr.substr(j));
	}
}

//renvoie la prochaine ligne, string "" si pas de '\n'
std::string const CircularBuffer::getLine()
{
	if (end == 0)
		return std::string("");
	int i;
	int j = start;
	for (i = start; (i < size || i < end) && buffer[i] != '\n'; ++i);
	if (buffer[i] == '\n')
	{
		start = i == size ? 0 : i + 1;
		if (i == end)
		{
			start = 0;
			end = 0;
		}
		return std::string(&buffer[j], i + 1 - j);
	}
	else if (i == end)
		return std::string("");
	else
		return getLine(std::string(&buffer[start], i + 1 - start));
}

//retourne la taille utilise du buffer
int CircularBuffer::getSize() const
{
	if (end == 0)
		return 0;
	else if (end > start)
		return end - start;
	else //end <= start
		return size - start + end;
}

//retourne la taille max du buffer
int CircularBuffer::getMaxSize() const
{
	return size;
}

int CircularBuffer::getEmptySize() const
{
	return this->getSize() - size;
}

bool CircularBuffer::isFull() const
{
	return getSize() == size;
}

//complete la string si tour du buffer (appel automatique)
std::string const CircularBuffer::getLine(std::string beginStr)
{
	int i = 0;
	for (i = 0; i < end && buffer[i] != '\n'; ++i);
	if (buffer[i] == '\n')
	{
		start = i;
		if (i == end)
		{
			start = 0;
			end = 0;
		}
		return beginStr.append(buffer, i + 1);
	}
	return std::string("");
}