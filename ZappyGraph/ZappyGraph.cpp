#include "ZappyGraph.hpp"

#include "State\MenuState.hpp"
#include "State\GameState.hpp"
#include "State\PauseState.hpp"
#include "State\SplashScreenState.hpp"

ZappyGraph::ZappyGraph()
{
	m_pAppStateManager = 0;
}

ZappyGraph::~ZappyGraph()
{
	delete m_pAppStateManager;
    delete OgreFramework::getSingletonPtr();
}

void ZappyGraph::startZappyGraphicalClient()
{
	new OgreFramework();
	if(!OgreFramework::getSingletonPtr()->initOgre("ZappyGraph", 0, 0))
		return;

	OgreFramework::getSingletonPtr()->m_pLog->logMessage("ZappyGraph initialized!");

	m_pAppStateManager = new AppStateManager();

	MenuState::create(m_pAppStateManager, "MenuState");
	GameState::create(m_pAppStateManager, "GameState");
    PauseState::create(m_pAppStateManager, "PauseState");
	SplashScreenState::create(m_pAppStateManager, "SplashScreenState");

	m_pAppStateManager->start(m_pAppStateManager->findByName("SplashScreenState"));
}
