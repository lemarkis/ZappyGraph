#include "Food.hpp"

Food::Food(Ogre::Entity * pEntity, Ogre::SceneNode * pNode)
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.1, .1, .1);
	node = pNode;
}

Food::~Food()
{
}
