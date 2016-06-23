#include "Cell.hpp"

Cell::Cell(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	node = pSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::String("Cell").append(std::to_string(pX))
		.append(".").append(std::to_string(pY)), Ogre::Vector3((Ogre::Real)pX * SIZE_CELL, 0, (Ogre::Real)pY * SIZE_CELL));
	Ogre::Entity * gEntity = pSceneMgr->createEntity("Ground.mesh");
	Ogre::SceneNode * gNode = node->createChildSceneNode();
	/*node->addChild(gNode);*/
}

Cell::~Cell()
{
}

Ogre::SceneNode * Cell::getNode() const
{
	return node;
}
