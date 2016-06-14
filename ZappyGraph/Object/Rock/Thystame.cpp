#include "Thystame.hpp"

Thystame::Thystame(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : ARock(pName)
{
	entity = pEntity;
	node = pNode;
}

Thystame::~Thystame()
{
}
