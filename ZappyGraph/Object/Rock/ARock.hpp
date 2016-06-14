#ifndef AROCK_HPP
#define AROCK_HPP

#include <Ogre.h>
#include "Object\AObject.hpp"

class ARock : public AObject
{
public:
	virtual ~ARock();

protected:
	ARock(Ogre::String const pName);

};

#endif // !AROCK_HPP
