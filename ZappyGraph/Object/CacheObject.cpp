#include "CacheObject.hpp"

template<> ObjectCache * Ogre::Singleton<ObjectCache>::msSingleton = 0;

ObjectCache::ObjectCache(Ogre::SceneManager * pSceneMgr)
{
	character = pSceneMgr->createEntity("Drone.mesh");
	ground = pSceneMgr->createEntity("Ground.mesh");
	linemate = pSceneMgr->createEntity("Linemate.mesh");
	deraumere = pSceneMgr->createEntity("Deraumere.mesh");
	sibur = pSceneMgr->createEntity("Sibur.mesh");
	mendiane = pSceneMgr->createEntity("Mendiane.mesh");
	phiras = pSceneMgr->createEntity("Phiras.mesh");
	thystame = pSceneMgr->createEntity("Thystame.mesh");
	food = pSceneMgr->createEntity("Oil.mesh");
	egg = pSceneMgr->createEntity("Oeuf.mesh");
}

ObjectCache::~ObjectCache()
{
}
