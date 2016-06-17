#include "Thystame.hpp"

Thystame::Thystame(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Thystame::~Thystame()
{
}
