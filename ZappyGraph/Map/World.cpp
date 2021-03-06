#include "World.hpp"

template<> World * Ogre::Singleton<World>::msSingleton = 0;

World::World(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	_map = new Cell**[pY];
	for (int i = 0; i < pY; ++i)
	{
		_map[i] = new Cell*[pX];
		for (int j = 0; j < pX; ++j)
		{
			_map[i][j] = new Cell(pSceneMgr, j, i);
		}
	}
	sizeX = pX;
	sizeY = pY;
}

World::~World()
{
	for (int i = 0; i < sizeY; ++i)
	{
		for (int j = 0; j < sizeX; ++j)
		{
			delete _map[i][j];
		}
		delete _map[i];
	}
	delete _map;
}

Cell * World::getCell(int const pX, int const pY) const
{
	return _map[pY][pX];
}

Character * World::getDrone(Ogre::String const & pName) const
{
	for (std::vector<Character*>::const_iterator it = drones.begin(); it != drones.end(); ++it)
	{
		if ((*it)->getNode()->getName() == pName)
		{
			return *it;
		}
	}
	return nullptr;
}

Egg * World::getEgg(Ogre::String const & pName) const
{
	for (std::vector<Egg*>::const_iterator it = eggs.end(); it != eggs.end(); it++)
	{
		if ((*it)->getNode()->getName() == pName)
		{
			return *it;
		}
	}
	return nullptr;
}
