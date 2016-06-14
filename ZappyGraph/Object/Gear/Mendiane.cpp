#include "Mendiane.hpp"

Mendiane::Mendiane(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AGear(pName)
{
	entity = pEntity;
	node = pNode;
}

Mendiane::
~Mendiane()
{
}
