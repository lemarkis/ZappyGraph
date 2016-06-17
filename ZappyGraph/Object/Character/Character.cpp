#include "Character.hpp"

Character::Character(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AObject(pName)
{
	entity = pEntity;
	node = pNode;
	node->attachObject(entity);
	setAnimation("idle");
}

Character::~Character()
{
}

void Character::setAnimation(Ogre::String const & pAnimName)
{	
	activeAnimation = entity->getAnimationState(pAnimName);
	activeAnimation->setLoop(true);
	activeAnimation->setEnabled(true);
}