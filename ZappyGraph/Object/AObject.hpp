#ifndef AOBJECT_HPP
#define AOBJECT_HPP

#include <Ogre.h>

class AObject
{
public:
	virtual ~AObject();

	virtual Ogre::Entity * getEntity() const;
	virtual Ogre::SceneNode * getNode() const;
	virtual Ogre::String const & getName() const;

protected:
	AObject(Ogre::String pName);

	Ogre::Entity * entity;
	Ogre::SceneNode * node;
	Ogre::String const name;

};

#endif // !AOBJECT_HPP
