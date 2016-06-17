#include "Deraumere.hpp"

Deraumere::Deraumere(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Deraumere::~Deraumere()
{
}