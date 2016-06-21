#ifndef IPCONNECT_HPP
#define IPCONNECT_HPP

#include <Ogre.h>

class IPConnect : public Ogre::Singleton<IPConnect>
{
public:
	IPConnect();
	~IPConnect();

	Ogre::String const getIP() const;
	int const getPort() const;

	Ogre::String	ipPort;

private:

};

#endif // !IPCONNECT_HPP
