#include "Cell.hpp"

Cell::Cell(Ogre::SceneManager * pSceneMgr)
{
	node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
}

Cell::~Cell()
{
}

Ogre::SceneNode * Cell::getNode() const
{
	return node;
}
