#include "Deraumere.hpp"

Deraumere::Deraumere(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear(pName)
{
	entity = pEntity;
	node = pNode;
}

Deraumere::~Deraumere()
{
}