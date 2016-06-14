#ifndef CELL_HPP
#define CELL_HPP

#include <Ogre.h>
#include "Object\Character\Character.hpp"
#include "Object\Gear\Deraumere.hpp"
#include "Object\Gear\Linemate.hpp"
#include "Object\Gear\Mendiane.hpp"
#include "Object\Gear\Phiras.hpp"
#include "Object\Gear\Sibur.hpp"
#include "Object\Gear\Thystame.hpp"

#define SIZE_CELL 2

class Cell
{
public:
	Cell(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	~Cell();

protected:
	Ogre::SceneNode * node;
	int x;
	int y;

};

#endif // !CELL_HPP
