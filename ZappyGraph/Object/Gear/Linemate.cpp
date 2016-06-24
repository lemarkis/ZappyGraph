#include "Linemate.hpp"

Linemate::Linemate(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.1, .1, .1);
	node->setPosition(0, 0, -.7);
	node = pNode;
}

Linemate::~Linemate()
{
}