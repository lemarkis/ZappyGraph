#ifndef MENDIANE_HPP
#define MENDIANE_HPP

#include "AGear.hpp"

class Mendiane : public AGear
{
public:
	Mendiane(Ogre::String const pName, Ogre::Entity * pEntity, Ogre::SceneNode * pNode);
	~Mendiane();

private:

};

#endif // !MENDIANE_HPP