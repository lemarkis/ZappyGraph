#include "Mendiane.hpp"

Mendiane::Mendiane(Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear()
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
}

Mendiane::
~Mendiane()
{
}
