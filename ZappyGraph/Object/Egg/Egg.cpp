#include "Egg.hpp"

Egg::Egg(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode)
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Egg::~Egg()
{
}

Ogre::Vector2 const Egg::getPosition() const
{
	return Ogre::Vector2(node->getPosition().x / SIZE_CELL, node->getPosition().z / SIZE_CELL);
}
