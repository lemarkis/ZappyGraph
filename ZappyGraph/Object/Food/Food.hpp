#ifndef FOOD_HPP
#define FOOD_HPP

#include "Object\AObject.hpp"

class Food : public AObject
{
public:
	Food(Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Food();

private:

};

#endif // !FOOD_HPP