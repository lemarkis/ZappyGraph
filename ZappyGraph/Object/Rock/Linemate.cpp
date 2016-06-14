#include "Linemate.hpp"

Linemate::Linemate(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : ARock(pName)
{
	entity = pEntity;
	node = pNode;
}

Linemate::~Linemate()
{
}