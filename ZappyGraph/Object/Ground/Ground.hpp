#ifndef GROUND_HPP
#define GROUND_HPP

#include "Object\AObject.hpp"

class Ground : public AObject
{
public:
	Ground(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Ground();

private:

};

#endif // !GROUND_HPP
