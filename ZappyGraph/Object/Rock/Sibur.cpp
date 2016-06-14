#include "Sibur.hpp"

Sibur::Sibur(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : ARock(pName)
{
	entity = pEntity;
	node = pNode;
}

Sibur::~Sibur()
{
}
