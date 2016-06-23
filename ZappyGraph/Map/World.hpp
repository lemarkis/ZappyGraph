#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include <Ogre.h>

#include "Map\Cell.hpp"
#include "Object\Character\Character.hpp"
#include "Object\Egg\Egg.hpp"

class Cell;

class World : public Ogre::Singleton<World>
{
public:
	World(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	~World();

	Cell ***_map;
	int sizeX, sizeY;
	Cell * getCell(int const pX, int const pY) const;

	std::vector<Character*> drones;
	Character * getDrone(Ogre::String const & pName) const;

	std::vector<Egg*> eggs;
	Egg * getEgg(Ogre::String const & pName) const;

private:

};

#endif // !MAP_HPP