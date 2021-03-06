#include "IPConnect.hpp"

template<> IPConnect* Ogre::Singleton<IPConnect>::msSingleton = 0;

IPConnect::IPConnect()
{
}

IPConnect::~IPConnect()
{
}

Ogre::String const IPConnect::getIP() const
{
	int pos = 0;
	int size = ipPort.size();
	for (Ogre::String::const_iterator it = ipPort.begin(); it < ipPort.end(); ++it)
	{
		++pos;
		if (*it == ':')
		{
			Ogre::String sub(ipPort.substr(0, pos - 1));
			//OgreFramework::getSingletonPtr()->m_pLog->logMessage(sub);
			return sub;
		}
	}
}

int const IPConnect::getPort() const
{
	int pos = 0;
	int size = ipPort.size();
	for (Ogre::String::const_iterator it = ipPort.begin(); it < ipPort.end(); ++it)
	{
		++pos;
		if (*it == ':')
		{
			return std::stoi(ipPort.substr(pos, size - pos));
		}
	}
}

	