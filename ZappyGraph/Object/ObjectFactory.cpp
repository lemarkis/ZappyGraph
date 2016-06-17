#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory()
{}

ObjectFactory::~ObjectFactory()
{}

Character * ObjectFactory::CreateCharacter(Ogre::SceneManager * pSceneMgr, int pX, int pY, Ogre::String const pName)
{
	Ogre::Entity * entity = pSceneMgr->createEntity(pName, "Drone.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode(pName);
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Character(pName, entity, node);
}

Deraumere * ObjectFactory::CreateDeraumere(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Demauree.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Deraumere(entity, node);
}

Linemate * ObjectFactory::CreateLinemate(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Linemate.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Linemate(entity, node);
}

Mendiane * ObjectFactory::CreateMendiane(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Mendiane.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Mendiane(entity, node);
}

Phiras * ObjectFactory::CreatePhiras(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Phiras.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Phiras(entity, node);
}

Sibur * ObjectFactory::CreateSibur(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Sibur.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Sibur(entity, node);
}

Thystame * ObjectFactory::CreateThystame(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Thystame.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	return new Thystame(entity, node);
}
