#include "Character.hpp"

Character::Character(Ogre::String const pName, Ogre::Entity const & pEntity, Ogre::SceneNode const & pNode) : AObject(pName), entity(pEntity), node(pNode)
{
	setAnimation(Animation::IDLE);
}

Character::~Character()
{
}

void Character::setAnimation(Animation pState) const
{
	switch (pState)
	{
	case Animation::IDLE:
		activeAnimation = entity->getAnimationState("idle");
		break;
	case Animation::WALK:
		activeAnimation = entity->getAnimationState("walk");
		break;
	case Animation::TAKE:
		activeAnimation = entity->getAnimationState("take");
		break;
	case Animation::DROP:
		activeAnimation = entity->getAnimationState("drop");
		break;
	case Animation::PUNCH:
		activeAnimation = entity->getAnimationState("punch");
		break;
	case Animation::INCANTE:
		activeAnimation = entity->getAnimationState("incante");
		break;
	default:
		break;
	}
	activeAnimation->setLoop(true);
	activeAnimation->setEnabled(true);
}