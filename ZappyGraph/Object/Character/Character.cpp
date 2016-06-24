#include "Character.hpp"

Character::Character(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode) : AObject(pName)
{
	entity = pEntity;
	node = pNode->createChildSceneNode();
	node->attachObject(entity);
	node->setScale(.4, .4, .4);
	node->setPosition(0, 0, -.25);
	node->setOrientation(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0, 1, 0)));
	node = pNode;
	/*setAnimation("idle");*/
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

Ogre::Vector2 const Character::getPosition() const
{
	return Ogre::Vector2(node->getPosition().x / SIZE_CELL, node->getPosition().z / SIZE_CELL);
}
