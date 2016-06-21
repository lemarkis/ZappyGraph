#include "GameState.hpp"

GameState::GameState()
{
	quit = false;
	frameEvent = Ogre::FrameEvent();
}

void GameState::enter()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Entering GameState...");

    sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->createSceneManager(Ogre::ST_GENERIC, "GameSceneMgr");
    sceneMgr->setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));

	sceneMgr->addRenderQueueListener(OgreFramework::getSingletonPtr()->m_pOverlaySystem);

    camera = sceneMgr->createCamera("GameCamera");
    camera->setPosition(Ogre::Vector3(5, 60, 60));
    camera->lookAt(Ogre::Vector3(5, 20, 0));
    camera->setNearClipDistance(5);

    camera->setAspectRatio(Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth()) /
        Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight()));

    OgreFramework::getSingletonPtr()->m_pViewport->setCamera(camera);
	
	try
	{
		socket = new Socket(IPConnect::getSingletonPtr()->getIP(), IPConnect::getSingletonPtr()->getPort());
		socket->socketConnect();
	}
	catch (const std::exception& e)
	{
		OgreFramework::getSingletonPtr()->m_pLog->logMessage(e.what());
		delete socket;
		socket = nullptr;
		changeAppState(findByName("MenuState"));
	}

	new ObjectFactory();
	new Protocole();

    buildGUI();

    createScene();
}

bool GameState::pause()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Pausing GameState...");

    return true;
}

void GameState::resume()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Resuming GameState...");

    buildGUI();

    OgreFramework::getSingletonPtr()->m_pViewport->setCamera(camera);
    quit = false;
}

void GameState::exit()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Leaving GameState...");

    sceneMgr->destroyCamera(camera);
    if(sceneMgr)
        OgreFramework::getSingletonPtr()->m_pRoot->destroySceneManager(sceneMgr);
	if (socket != nullptr)
	{
		socket->socketClose();
		delete socket;
		socket = nullptr;
	}
	delete Protocole::getSingletonPtr();
	delete ObjectFactory::getSingletonPtr();
}

void GameState::createScene()
{
    sceneMgr->createLight("Light")->setPosition(75,75,75);

	Ogre::String msg;
	socket->socketRead(msg);
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [Internet] : ").append(msg.substr(0, msg.size() - 1)));
	if (socket->socketWrite("GRAPHIC\n") <= 0)
	{
		socket->socketClose();
		changeAppState(findByName("MenuState"));
	}
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String(">>> [Internet] : ").append("GRAPHIC"));
}

bool GameState::keyPressed(const OIS::KeyEvent &keyEventRef)
{
	if (OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_ESCAPE))
	{
		pushAppState(findByName("PauseState"));
		return true;
	}
	
    return true;
}

bool GameState::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    OgreFramework::getSingletonPtr()->keyPressed(keyEventRef);
    return true;
}

bool GameState::mouseMoved(const OIS::MouseEvent &evt)
{
	return true;
}

bool GameState::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    return true;
}

bool GameState::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    return true;
}

void GameState::onLeftPressed(const OIS::MouseEvent &evt)
{

}

void GameState::moveCamera()
{

}

void GameState::getInput()
{

}

void GameState::update(double timeSinceLastFrame)
{
    m_FrameEvent.timeSinceLastFrame = timeSinceLastFrame;

    if(quit == true)
    {
        popAppState();
        return;
    }

	socket->socketFD_ZERO(&fd_read);
	socket->socketFD_ZERO(&fd_write);
	socket->socketFD_SET(&fd_read);
	socket->socketFD_SET(&fd_write);
	socket->socketSelect(&fd_read, &fd_write);
	if (FD_ISSET(socket->getSock(), &fd_read))
	{
		Ogre::String msg;
		socket->socketRead(msg);
		OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [Internet] : ").append(msg.substr(0, msg.size() - 1)));
		quit = Protocole::getSingletonPtr()->parseMsg(msg);
	}

    getInput();
    moveCamera();
}

void GameState::buildGUI()
{
    
}
