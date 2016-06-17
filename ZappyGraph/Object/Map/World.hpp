#ifndef MAP_HPP
#define MAP_HPP

#include <map>

#include <Ogre.h>

#include "Cell.hpp"

class Cell;

class World : public Ogre::Singleton<World>
{
public:
	World(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	~World();

	Cell ***_map;

	Cell * getCell(int const pX, int const pY) const;

private:

};

#endif // !MAP_HPP