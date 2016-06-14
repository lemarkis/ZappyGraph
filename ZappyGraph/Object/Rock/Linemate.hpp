#ifndef LINEMATE_HPP
#define LINEMATE_HPP

#include "ARock.hpp"

class Linemate : public ARock
{
public:
	Linemate(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Linemate();

private:

};

#endif // !LINEMATE_HPP
