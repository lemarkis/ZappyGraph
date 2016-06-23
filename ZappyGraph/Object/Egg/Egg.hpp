#ifndef EGG_HPP
#define EGG_HPP

#include <Ogre.h>
#include "Object\AObject.hpp"

class Egg : public AObject
{
public:
	Egg(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Egg();

	Ogre::Vector2 const getPosition() const;

private:

};

#endif // !EGG_HPP
