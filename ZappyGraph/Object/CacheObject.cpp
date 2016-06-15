#include "CacheObject.hpp"

template<> ObjectCache * Ogre::Singleton<ObjectCache>::msSingleton = 0;

ObjectCache::ObjectCache(Ogre::SceneManager * pSceneMgr)
{
	character = pSceneMgr->createEntity("Character.mesh");
	ground = pSceneMgr->createEntity("Character.mesh");
	linemate = pSceneMgr->createEntity("Linemate.mesh");
	deraumere = pSceneMgr->createEntity("Deraumere.mesh");
	sibur = pSceneMgr->createEntity("Sibur.mesh");
	mendiane = pSceneMgr->createEntity("Mendiane.mesh");
	phiras = pSceneMgr->createEntity("Phiras.mesh");
	thystame = pSceneMgr->createEntity("Thystame.mesh");
}

ObjectCache::~ObjectCache()
{
}