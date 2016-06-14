#include "Ground.hpp"

Ground::Ground(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AObject(pName)
{
	entity = pEntity;
	node = pNode;
}

Ground::~Ground()
{
}
