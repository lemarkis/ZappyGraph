#include "Mendiane.hpp"

Mendiane::Mendiane(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : ARock(pName)
{
	entity = pEntity;
	node = pNode;
}

Mendiane::
~Mendiane()
{
}
