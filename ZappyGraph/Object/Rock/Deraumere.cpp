#include "Deraumere.hpp"

Deraumere::Deraumere(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : ARock(pName)
{
	entity = pEntity;
	node = pNode;
}

Deraumere::~Deraumere()
{
}