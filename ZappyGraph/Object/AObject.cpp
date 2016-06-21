#include "AObject.hpp"

AObject::AObject(Ogre::String pName): name(pName), node(nullptr), entity(nullptr)
{
}

AObject::AObject()
{
}

AObject::~AObject()
{
}

Ogre::Entity * AObject::getEntity() const
{
	return entity;
}

Ogre::SceneNode * AObject::getNode() const
{
	return node;
}

Ogre::String const & AObject::getName() const
{
	return name;
}