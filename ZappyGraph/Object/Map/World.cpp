#include "World.hpp"

template<> World * Ogre::Singleton<World>::msSingleton = 0;

World::World(Ogre::SceneManager * pSceneMgre, int pX, int pY)
{
	_map = new Cell**[pY];
	for (int i = 0; i < pY; ++i)
	{
		_map[i] = new Cell*[pX];
		for (int j = 0; j < pX; ++j)
		{
			_map[i][j] = new Cell(pSceneMgre);
		}
	}
}

World::~World()
{
}

Cell * World::getCell(int const pX, int const pY) const
{
	return _map[pY][pX];
}
