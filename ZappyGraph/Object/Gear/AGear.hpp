#ifndef AGEAR_HPP
#define AGEAR_HPP

#include <Ogre.h>
#include "Object\AObject.hpp"

class AGear : public AObject
{
public:
	virtual ~AGear();

protected:
	AGear(Ogre::String const pName = "NoName");

};

#endif // !AGEAR_HPP
