#include "Phiras.hpp"

Phiras::Phiras(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.05, .05, .05);
	node->setPosition(-.606, 0, .35);
	node = pNode;
}

Phiras::~Phiras()
{
}
