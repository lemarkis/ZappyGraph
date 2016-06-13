#ifndef AOBJECT_HPP
#define AOBJECT_HPP

#include <Ogre.h>

class AObject
{
public:
	AObject(Ogre::String pName);
	virtual ~AObject();

	virtual Ogre::Entity * getEntity() const;
	virtual Ogre::SceneNode * getNode() const;
	virtual Ogre::String const & getName() const;

protected:
	Ogre::Entity * entity;
	Ogre::SceneNode * node;
	Ogre::String const name;

};

#endif // !AOBJECT_HPP
