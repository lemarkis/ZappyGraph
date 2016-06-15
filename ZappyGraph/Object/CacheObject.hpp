#ifndef OBJECTCACHE_HPP
#define OBJECTCACHE_HPP

#include <Ogre.h>

class ObjectCache : public Ogre::Singleton<ObjectCache>
{
public:
	ObjectCache(Ogre::SceneManager * pSceneMgr);
	~ObjectCache();

private:
	Ogre::Entity * character;
	Ogre::Entity * ground;
	Ogre::Entity * linemate;
	Ogre::Entity * deraumere;
	Ogre::Entity * sibur;
	Ogre::Entity * mendiane;
	Ogre::Entity * phiras;
	Ogre::Entity * thystame;
};

#endif // !OBJECTCACHE_HPP
