#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Ogre.h>
#include "AObject.hpp"

class Character : public AObject
{
public:
	Character(Ogre::String const pName, Ogre::Entity const & pEntity, Ogre::SceneNode const & pNode);
	~Character();

	void setAnimation(Animation pState) const;

protected:
	Ogre::AnimationState * activeAnimation;

};

enum Animation
{
	IDLE, WALK,
	TAKE, DROP,
	PUNCH, INCANTE,
};


#endif // !CHARACTER_HPP
