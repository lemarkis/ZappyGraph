#include "Thystame.hpp"

Thystame::Thystame(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.01, .01, .01);
	node->setPosition(-.606, 0, -.4);
	node = pNode;
}

Thystame::~Thystame()
{
}
