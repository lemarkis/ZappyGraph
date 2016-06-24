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
	Ogre::SceneNode * node = World::getSingletonPtr()->getCell(pX, pY)->getNode()->createChildSceneNode(name);
	//TODO rotation en fonction du mesh
	Character * drone = new Character(name, entity, node);
	World::getSingletonPtr()->drones.push_back(drone);
	return drone;
}

Egg * ObjectFactory::CreateEgg(Ogre::SceneManager * pSceneMgr, int pX, int pY, int pNumEgg)
{
	Ogre::String name = Ogre::String(std::to_string(pNumEgg));
	Ogre::Entity * entity = pSceneMgr->createEntity(name, "Oeuf.mesh");
	Ogre::SceneNode * node = World::getSingletonPtr()->getCell(pX, pY)->getNode()->createChildSceneNode(name);
	Egg * egg = new Egg(name, entity, node);
	World::getSingletonPtr()->eggs.push_back(egg);
	return egg;
}

Deraumere * ObjectFactory::CreateDeraumere(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Deraumere.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Deraumere * tmp = new Deraumere(entity, node);
	cell->_deraumere.push(tmp);
	return tmp;
}

Linemate * ObjectFactory::CreateLinemate(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Linemate.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Linemate * tmp = new Linemate(entity, node);
	cell->_linemate.push(tmp);
	return tmp;
}

Mendiane * ObjectFactory::CreateMendiane(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Mendiane.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Mendiane * tmp = new Mendiane(entity, node);
	cell->_mendiane.push(tmp);
	return tmp;
}

Phiras * ObjectFactory::CreatePhiras(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Phiras.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Phiras * tmp = new Phiras(entity, node);
	cell->_phiras.push(tmp);
	return tmp;
}

Sibur * ObjectFactory::CreateSibur(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Sibur.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Sibur * tmp = new Sibur(entity, node);
	cell->_sibur.push(tmp);
	return tmp;
}

Thystame * ObjectFactory::CreateThystame(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Thystame.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
	Thystame * tmp = new Thystame(entity, node);
	cell->_thystame.push(tmp);
	return tmp;
}

Food * ObjectFactory::CreateFood(Ogre::SceneManager * pSceneMgr, int pX, int pY)
{
	Ogre::Entity * entity = pSceneMgr->createEntity("Oil.mesh");
	Cell * cell = World::getSingletonPtr()->getCell(pX, pY);
	Ogre::SceneNode * node = cell->getNode()->createChildSceneNode();
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
