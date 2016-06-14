#ifndef MENDIANE_HPP
#define MENDIANE_HPP

#include "ARock.hpp"

class Mendiane : public ARock
{
public:
	Mendiane(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Mendiane();

private:

};

#endif // !MENDIANE_HPP