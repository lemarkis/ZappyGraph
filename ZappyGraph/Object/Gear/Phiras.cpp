#include "Phiras.hpp"

Phiras::Phiras(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Phiras::~Phiras()
{
}
