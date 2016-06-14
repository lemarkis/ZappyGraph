#ifndef THYSTAME_HPP
#define THYSTAME_HPP

#include "ARock.hpp"

class Thystame : public ARock
{
public:
	Thystame(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Thystame();

private:

};

#endif // !THYSTAME_HPP