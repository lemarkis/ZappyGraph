#ifndef THYSTAME_HPP
#define THYSTAME_HPP

#include "AGear.hpp"

class Thystame : public AGear
{
public:
	Thystame(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Thystame();

private:

};

#endif // !THYSTAME_HPP