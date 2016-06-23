#include "ObjectFactory.hpp"

template<> ObjectFactory * Ogre::Singleton<ObjectFactory>::msSingleton = 0;

ObjectFactory::ObjectFactory()
{}

ObjectFactory::~ObjectFactory()
{}

Character * ObjectFactory::CreateCharacter(Ogre::SceneManager * pSceneMgr, int pX, int pY, int pOrientation, Ogre::String pTeamName, int pNumJoueur)
{
	/*pTeamName).append(*/
	Ogre::String name = Ogre::String(std::to_string(pNumJoueur));
	Ogre::Entity * entity = pSceneMgr->createEntity(name, "Drone.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode(name);
	//TODO rotation en fonction du mesh
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	Character * drone = new Character(name, entity, node);
	World::getSingletonPtr()->drones.push_back(drone);
	return drone;
}

Egg * ObjectFactory::CreateEgg(Ogre::SceneManager * pSceneMgr, int pX, int pY, int pNumEgg)
{
	Ogre::String name = Ogre::String(std::to_string(pNumEgg));
	Ogre::Entity * entity = pSceneMgr->createEntity(name, "Egg.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode(name);
	World::getSingletonPtr()->getCell(pX, pY)->getNode()->addChild(node);
	Egg * egg = new Egg(name, entity, node);
	World::getSingletonPtr()->eggs.push_back(egg);
	return egg;
}

Deraumere * ObjectFactory::CreateDeraumere(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Deraumere.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Deraumere * tmp = new Deraumere(entity, node);
	cell->_deraumere.push(tmp);
	return tmp;
}

Linemate * ObjectFactory::CreateLinemate(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Linemate.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Linemate * tmp = new Linemate(entity, node);
	cell->_linemate.push(tmp);
	return tmp;
}

Mendiane * ObjectFactory::CreateMendiane(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Mendiane.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Mendiane * tmp = new Mendiane(entity, node);
	cell->_mendiane.push(tmp);
	return tmp;
}

Phiras * ObjectFactory::CreatePhiras(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Phiras.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Phiras * tmp = new Phiras(entity, node);
	cell->_phiras.push(tmp);
	return tmp;
}

Sibur * ObjectFactory::CreateSibur(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Sibur.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Sibur * tmp = new Sibur(entity, node);
	cell->_sibur.push(tmp);
	return tmp;
}

Thystame * ObjectFactory::CreateThystame(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Thystame.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Thystame * tmp = new Thystame(entity, node);
	cell->_thystame.push(tmp);
	return tmp;
}

Food * ObjectFactory::CreateFood(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Food.mesh");
	Ogre::SceneNode * node = pSceneMgr->getRootSceneNode()->createChildSceneNode();
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	cell->getNode()->addChild(node);
	Food * tmp = new Food(entity, node);
	cell->_food.push(tmp);
	return tmp;
}

void DestroyCharacter(Ogre::String const pName)
{

}

void DestroyDeraumere(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_deraumere.pop();
}

void DestroyLinemate(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_linemate.pop();
}

void DestroyMendiane(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_mendiane.pop();
}

void DestroyPhiras(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_phiras.pop();
}

void DestroySibur(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_sibur.pop();
}

void DestroyThystame(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_thystame.pop();
}

void DestroyFood(int pX, int pY)
{
	World::getSingletonPtr()->getCell(pX, pY)->_food.pop();
}
