#include "Mendiane.hpp"

Mendiane::Mendiane(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.07, .07, .07);
	node->setPosition(0, 0, .7);
	node = pNode;
}

Mendiane::~Mendiane()
{
}
