#ifndef OBJECTFACTORY_HPP
#define OBJECTFACTORY_HPP

#include "Map\World.hpp"
#include "Object\Character\Character.hpp"
#include "Object\Egg\Egg.hpp"
#include "Object\Gear\Deraumere.hpp"
#include "Object\Gear\Linemate.hpp"
#include "Object\Gear\Mendiane.hpp"
#include "Object\Gear\Phiras.hpp"
#include "Object\Gear\Sibur.hpp"
#include "Object\Gear\Thystame.hpp"
#include "Object\Food\Food.hpp"

class ObjectFactory : public Ogre::Singleton<ObjectFactory>
{
public:
	ObjectFactory();
	~ObjectFactory();

	//--- Create ---

	Character * CreateCharacter(Ogre::SceneManager * pSceneMgr, int pX, int pY, int pOrientation, Ogre::String pTeamName, int pNumJoueur);
	Egg * CreateEgg(Ogre::SceneManager * pSceneMgr, int pX, int pY, int pNumEgg);

	Deraumere * CreateDeraumere(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Linemate * CreateLinemate(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Mendiane * CreateMendiane(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Phiras * CreatePhiras(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Sibur * CreateSibur(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Thystame * CreateThystame(Ogre::SceneManager * pSceneMgr, int pX, int pY);
	Food * CreateFood(Ogre::SceneManager * pSceneMgr, int pX, int pY);

	//--- Destroy ---

	void DestroyCharacter(Ogre::String const pName);

	void DestroyDeraumere(int pX, int pY);
	void DestroyLinemate(int pX, int pY);
	void DestroyMendiane(int pX, int pY);
	void DestroyPhiras(int pX, int pY);
	void DestroySibur(int pX, int pY);
	void DestroyThystame(int pX, int pY);
	void DestroyFood(int pX, int pY);

private:
};

#endif // !OBJECTFACTORY_HPP
