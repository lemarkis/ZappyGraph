#include "Thystame.hpp"

Thystame::Thystame(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear(pName)
{
	entity = pEntity;
	node = pNode;
}

Thystame::~Thystame()
{
}
