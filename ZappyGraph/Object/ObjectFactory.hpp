#ifndef OBJECTFACTORY_HPP
#define OBJECTFACTORY_HPP

#include "Object\Character\Character.hpp"
#include "Object\Gear\Deraumere.hpp"
#include "Object\Gear\Linemate.hpp"
#include "Object\Gear\Mendiane.hpp"
#include "Object\Gear\Phiras.hpp"
#include "Object\Gear\Sibur.hpp"
#include "Object\Gear\Thystame.hpp"

class ObjectFactory
{
public:
	~ObjectFactory();

	//--- Create ---
	Character * CreateCharacter(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);

	Deraumere * CreateDeraumere(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);
	Linemate * CreateLinemate(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);
	Mendiane * CreateMendiane(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);
	Phiras * CreatePhiras(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);
	Sibur * CreateSibur(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);
	Thystame * CreateThystame(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);

	cell * CreateCell(Ogre::SceneManager * pSceneMgr, Ogre::String const pName, int pX, int pY);

	//--- Destroy ---
	void DestroyCharacter(Ogre::String const pName);

	void DestroyDeraumere(Ogre::String const pName);
	void DestroyLinemate(Ogre::String const pName);
	void DestroyMendiane(Ogre::String const pName);
	void DestroyPhiras(Ogre::String const pName);
	void DestroySibur(Ogre::String const pName);
	void DestroyThystame(Ogre::String const pName);

private:

};

#endif // !OBJECTFACTORY_HPP
