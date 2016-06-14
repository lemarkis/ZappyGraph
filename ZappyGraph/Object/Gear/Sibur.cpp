#include "Sibur.hpp"

Sibur::Sibur(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear(pName)
{
	entity = pEntity;
	node = pNode;
}

Sibur::~Sibur()
{
}
