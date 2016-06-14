#ifndef LINEMATE_HPP
#define LINEMATE_HPP

#include "AGear.hpp"

class Linemate : public AGear
{
public:
	Linemate(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Linemate();

private:

};

#endif // !LINEMATE_HPP
