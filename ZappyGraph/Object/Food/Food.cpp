#include "Food.hpp"

Food::Food(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AObject()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Food::~Food()
{
}
