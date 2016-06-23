#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Ogre.h>
#include "Object\AObject.hpp"

class Character : public AObject
{
public:
	Character(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Character();

	void setAnimation(Ogre::String const & pAnimName);
	Ogre::Vector2 const getPosition() const;

protected:
	Ogre::AnimationState * activeAnimation;

};

#endif // !CHARACTER_HPP
