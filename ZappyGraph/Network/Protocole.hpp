#ifndef PROTOCOLE_HPP
#define PROTOCOLE_HPP

#include <Ogre.h>
#include "Framework\AdvancedOgreFramework.hpp"
#include <map>
#include "Map\World.hpp"
#include "Object\ObjectFactory.hpp"

class Protocole : public Ogre::Singleton<Protocole>
{
public:
	Protocole();
	~Protocole();

	bool parseMsg(Ogre::String msg);

	bool getSizeMap(std::stringstream & msg);
	bool getTimeUnit(std::stringstream & msg);
	bool getTeamName(std::stringstream & msg);
	bool getCellRes(std::stringstream & msg);
	bool newPlayer(std::stringstream & msg);
	bool getPlayerPos(std::stringstream & msg);
	bool getPlayerLvl(std::stringstream & msg);
	bool getPlayerInv(std::stringstream & msg);
	bool playerExpls(std::stringstream & msg);
	bool playerBrdcst(std::stringstream & msg);
	bool playerInct(std::stringstream & msg);
	bool inctEnd(std::stringstream & msg);
	bool playerFork(std::stringstream & msg);
	bool playerDrop(std::stringstream & msg);
	bool playerTake(std::stringstream & msg);
	bool playerDie(std::stringstream & msg);
	bool eggSpawn(std::stringstream & msg);
	bool eggHatch(std::stringstream & msg);
	bool playerToEgg(std::stringstream & msg);
	bool eggDie(std::stringstream & msg);
	bool gameEnd(std::stringstream & msg);
	bool msgServer(std::stringstream & msg);
	bool cmdUnknow(std::stringstream & msg);
	bool cmdBadArg(std::stringstream & msg);

private:
	Ogre::String cmd;
	std::map<std::string, bool (Protocole::*)(std::stringstream &)> funcMap;
};

#endif // !PROTOCOLE_HPP
