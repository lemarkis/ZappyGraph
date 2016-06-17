#include "Sibur.hpp"

Sibur::Sibur(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Sibur::~Sibur()
{
}
