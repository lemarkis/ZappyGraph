#ifndef CELL_HPP
#define CELL_HPP

#include <Ogre.h>
#include <stack>

#include "Object\ObjectFactory.hpp"
#include "Object\Food\Food.hpp"
#include "Object\Gear\Deraumere.hpp"
#include "Object\Gear\Linemate.hpp"
#include "Object\Gear\Mendiane.hpp"
#include "Object\Gear\Phiras.hpp"
#include "Object\Gear\Sibur.hpp"
#include "Object\Gear\Thystame.hpp"

class Cell
{
public:
	Cell(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	~Cell();

	Ogre::SceneNode * getNode() const;
	std::stack<Deraumere*> _deraumere;
	std::stack<Linemate*> _linemate;
	std::stack<Mendiane*> _mendiane;
	std::stack<Phiras*> _phiras;
	std::stack<Sibur*> _sibur;
	std::stack<Thystame*> _thystame;
	std::stack<Food*> _food;

protected:
	Ogre::SceneNode * node;
	
};

#endif // !CELL_HPP
