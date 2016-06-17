#include "Linemate.hpp"

Linemate::Linemate(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Linemate::~Linemate()
{
}