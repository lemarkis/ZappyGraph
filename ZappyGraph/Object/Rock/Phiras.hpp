#ifndef PHIRAS_HPP
#define PHIRAS_HPP

#include "ARock.hpp"

class Phiras : public ARock
{
public:
	Phiras(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Phiras();

private:

};

#endif // !PHIRAS_HPP