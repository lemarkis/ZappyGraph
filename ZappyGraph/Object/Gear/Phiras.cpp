#include "Phiras.hpp"

Phiras::Phiras(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear(pName)
{
	entity = pEntity;
	node = pNode;
}

Phiras::~Phiras()
{
}
