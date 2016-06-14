#include "Cell.hpp"

Cell::Cell(Ogre::SceneManager * pSceneMgr, int pX, int pY) : x(pX), y(pY)
{
	node = pSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::String("Cell").append(std::to_string(pX))
		.append(".").append(std::to_string(pY)), Ogre::Vector3(pX * SIZE_CELL, 0, pY * SIZE_CELL));
}

Cell::~Cell()
{
}
