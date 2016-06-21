#include "Protocole.hpp"

template<> Protocole * Ogre::Singleton<Protocole>::msSingleton = 0;

Protocole::Protocole()
{
	funcMap["msz"] = &Protocole::getSizeMap;
	funcMap["sgt"] = &Protocole::getTimeUnit;
	funcMap["tna"] = &Protocole::getTeamName;
	funcMap["pnw"] = &Protocole::newPlayer;
	funcMap["ppo"] = &Protocole::getPlayerPos;
	funcMap["piv"] = &Protocole::getPlayerPos;
	funcMap["pin"] = &Protocole::getPlayerLvl;
	funcMap["pex"] = &Protocole::playerExpls;
	funcMap["pbc"] = &Protocole::playerBrdcst;
	funcMap["pic"] = &Protocole::playerInct;
	funcMap["pie"] = &Protocole::inctEnd;
	funcMap["pfk"] = &Protocole::playerFork;
	funcMap["pdr"] = &Protocole::playerDrop;
	funcMap["pgt"] = &Protocole::playerTake;
	funcMap["pdi"] = &Protocole::playerDie;
	funcMap["enw"] = &Protocole::eggSpawn;
	funcMap["eht"] = &Protocole::eggHatch;
	funcMap["ebo"] = &Protocole::playerToEgg;
	funcMap["edi"] = &Protocole::eggDie;
	funcMap["seg"] = &Protocole::gameEnd;
	funcMap["smg"] = &Protocole::msgServer;
	funcMap["suc"] = &Protocole::cmdUnknow;
	funcMap["sbp"] = &Protocole::cmdBadArg;
}

Protocole::~Protocole()
{
	funcMap.clear();
}

bool Protocole::parseMsg(Ogre::String msg)
{
	std::stringstream tmp(msg);
	Ogre::String cmd;
	tmp >> cmd;
	for (std::map<Ogre::String, bool (Protocole::*)(std::stringstream &)>::iterator it = funcMap.begin(); it != funcMap.end(); ++it)
	{
		if ((*it).first == cmd)
			return (this->*(it->second))(tmp);
	}
	return false;
}

// msz X Y\n
bool Protocole::getSizeMap(std::stringstream & msg)
{
	int x, y;
	msg >> x >> y;
	Ogre::SceneManager * sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->getSceneManager("GameSceneMgr");
	if (World::getSingletonPtr() == nullptr)
	{
		OgreFramework::getSingletonPtr()->m_pLog->logMessage("Creating Map...");
		new World(sceneMgr, x, y);
		OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Map ").append(std::to_string(x)).append("x").append(std::to_string(y)).append(" created."));
	}
	else
	{
		OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Map already exist (").append(std::to_string(x)).append("x").append(std::to_string(y)).append(")."));
	}
	return false;
}

// sgt T\n
bool Protocole::getTimeUnit(std::stringstream & msg)
{
	int unitTime;
	msg >> unitTime;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Unit Time: ").append(std::to_string(unitTime)));
	return false;
}

// tna N\n
bool Protocole::getTeamName(std::stringstream & msg)
{
	Ogre::String teamName;
	msg >> teamName;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Team name: ").append(teamName));
	return false;
}

// pnw #n X Y O L\n
bool Protocole::newPlayer(std::stringstream & msg)
{
	Ogre::String teamName;
	int n, x, y, o, l;
	msg >> n >> x >> y >> o >> l >> teamName;
	Ogre::SceneManager * sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->getSceneManager("GameSceneMgr");
	ObjectFactory::getSingletonPtr()->CreateCharacter(sceneMgr, x, y, o, teamName, n);
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Creating player: ").append(std::to_string(n)).append(" ")
		.append(std::to_string(x)).append(" ").append(std::to_string(y)).append(" ").append(std::to_string(o)));
	return false;
}

// ppo #n X Y O\n
bool Protocole::getPlayerPos(std::stringstream & msg)
{
	int x, y, o, n;
	msg >> n >> x >> y >> o;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player position: ").append(std::to_string(n)).append(" ")
		.append(std::to_string(x)).append(" ").append(std::to_string(y)).append(" ").append(std::to_string(o)));
	return false;
}

// plv #n L\n
bool Protocole::getPlayerLvl(std::stringstream & msg)
{
	int n, l;
	msg >> n >> l;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player level: ").append(std::to_string(n)).append(" ")
		.append(std::to_string(l)));
	return false;
}

// pin # X Y q q q q q q q\n
bool Protocole::getPlayerInv(std::stringstream & msg)
{
	int n, x, y, f, l, d, s, m, p, t;
	msg >> n >> x >> y >> f >> l >> d >> s >> m >> p >> t;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player inventaire: ").append(std::to_string(n)).append(" ")
		.append(std::to_string(f)).append(std::to_string(l)).append(" ").append(std::to_string(d)).append(" ").append(std::to_string(s)).append(" ")
		.append(std::to_string(m)).append(" ").append(std::to_string(p)).append(" ").append(std::to_string(t)));
	return false;
}

// pex #n\n
bool Protocole::playerExpls(std::stringstream & msg)
{
	int n;
	msg >> n;
	//TODO get joueur pour animation
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player expulse: ").append(std::to_string(n)));
	return false;
}

// pbc #n M\n
bool Protocole::playerBrdcst(std::stringstream & msg)
{
	int n;
	Ogre::String brdcst;
	msg >> n >> brdcst;
	//TODO create box with brdcst
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player broadcast: ").append(std::to_string(n)).append(brdcst));
	return false;
}

// pic X Y L #n #n ...\n 
bool Protocole::playerInct(std::stringstream & msg)
{
	int x, y, l, n, n2, n3, n4, n5, n6;
	msg >> x >> y >> l >> n >> n2 >> n3 >> n4 >> n5 >> n6;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Player incantation: ").append(std::to_string(x)).append(";").append(std::to_string(y))
		.append(" ").append(std::to_string(n)).append(" ").append(std::to_string(n2)).append(" ").append(std::to_string(n3))
		.append(" ").append(std::to_string(n4)).append(" ").append(std::to_string(n5)).append(" ").append(std::to_string(n6)));
	return false;
}

// pie X Y R\n
bool Protocole::inctEnd(std::stringstream & msg)
{
	int x, y, r;
	msg >> x >> y >> r;

	return false;
}

// pfk #n\n
bool Protocole::playerFork(std::stringstream & msg)
{
	return false;
}

// pdr #n i\n
bool Protocole::playerDrop(std::stringstream & msg)
{
	int n, i;
	msg >> n >> i;
	Ogre::SceneManager * sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->getSceneManager("GameSceneMgr");
	switch (i)
	{
	case 0:
		//ObjectFactory::getSingletonPtr()->CreateFood(sceneMgr, );
		//break;
	case 1:
		//Linemate
		//break;
	case 2:
		//Deraumere
		//break;
	case 3:
		//Sibur
		//break;
	case 4:
		//Mendiane
		//break;
	case 5:
		//Phiras
		//break;
	case 6:
		//Thystame
		//break;
	default:
		break;
	}
	return false;
}

// pgt #n i\n
bool Protocole::playerTake(std::stringstream & msg)
{
	int n, i;
	msg >> n >> i;
	Ogre::SceneManager * sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->getSceneManager("GameSceneMgr");
	switch (i)
	{
	case 0:
		//ObjectFactory::getSingletonPtr()->DestroyFood();
		//break;
	case 1:
		//Linemate
		//break;
	case 2:
		//Deraumere
		//break;
	case 3:
		//Sibur
		//break;
	case 4:
		//Mendiane
		//break;
	case 5:
		//Phiras
		//break;
	case 6:
		//Thystame
		//break;
	default:
		break;
	}
	return false;
}

// pdi #n\n
bool Protocole::playerDie(std::stringstream & msg)
{

	return false;
}

// enw #e #n X Y\n
bool Protocole::eggSpawn(std::stringstream & msg)
{
	return false;
}

// eht #e\n
bool Protocole::eggHatch(std::stringstream & msg)
{
	return false;
}

// ebo #e\n
bool Protocole::playerToEgg(std::stringstream & msg)
{
	return false;
}

// edi #e\n
bool Protocole::eggDie(std::stringstream & msg)
{
	return false;
}

// seg #N\n
bool Protocole::gameEnd(std::stringstream & msg)
{
	return true;
}

// smg M\n
bool Protocole::msgServer(std::stringstream & msg)
{
	Ogre::String smsg;
	msg >> smsg;
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("Message Server: ").append(smsg));
	return false;
}

// suc\n
bool Protocole::cmdUnknow(std::stringstream & msg)
{
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Unknow command");
	return false;
}

// sbp\n
bool Protocole::cmdBadArg(std::stringstream & msg)
{
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Bad argument in last command");
	return false;
}
