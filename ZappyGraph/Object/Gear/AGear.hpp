#ifndef AGEAR_HPP
#define AGEAR_HPP

#include <Ogre.h>
#include "Object\AObject.hpp"

class AGear : public AObject
{
public:
	virtual ~AGear();

protected:
	AGear(Ogre::String const pName);

};

#endif // !AGEAR_HPP
