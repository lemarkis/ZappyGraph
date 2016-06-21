#ifndef MAP_HPP
#define MAP_HPP

#include <map>

#include <Ogre.h>

#include "Map\Cell.hpp"

class Cell;

class World : public Ogre::Singleton<World>
{
public:
	World(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	~World();

	Cell ***_map;
	int sizeX, sizeY;
	Cell * getCell(int const pX, int const pY) const;

private:

};

#endif // !MAP_HPP