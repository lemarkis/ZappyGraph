#include "GameState.hpp"

GameState::GameState()
{
	quit = false;
	socketOK = false;
	socket = nullptr;
	cb_read = nullptr;
	frameEvent = Ogre::FrameEvent();

	m_MoveSpeed = 0.1f;
	m_RotateSpeed = 0.3f;
}

void GameState::enter()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Entering GameState...");

    sceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->createSceneManager(Ogre::ST_GENERIC, "GameSceneMgr");
    sceneMgr->setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));

	sceneMgr->addRenderQueueListener(OgreFramework::getSingletonPtr()->m_pOverlaySystem);

    camera = sceneMgr->createCamera("GameCamera");
    camera->setPosition(Ogre::Vector3(0, 20, 20));
    camera->lookAt(Ogre::Vector3(0, 0, 0));
    camera->setNearClipDistance(2);

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
		return;
	}
	
	cb_read = new CircularBuffer(8192);
	new ObjectFactory();
	new Protocole();

    buildGUI();

    createScene();

	socketOK = true;
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
	delete cb_read;
	delete Protocole::getSingletonPtr();
	delete ObjectFactory::getSingletonPtr();
}

void GameState::createScene()
{
    sceneMgr->createLight("Light")->setPosition(0,75,0);

	Ogre::String msg;
	socket->socketRead(msg);
	OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [RAW Internet] : ").append(msg));
	//OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [Internet] : ").append(msg.substr(0, msg.size() - 1)));
	if (socket->socketWrite("GRAPHIC\n") <= 0)
	{
		socket->socketClose();
		changeAppState(findByName("MenuState"));
	}
	else
	{
		OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String(">>> [Internet] : ").append("GRAPHIC\\n"));
	}
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
	//if (OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseMove(evt)) return true;

	camera->yaw(Ogre::Degree(evt.state.X.rel * -0.1f));
	camera->pitch(Ogre::Degree(evt.state.Y.rel * -0.1f));

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
	camera->move(m_TranslateVector * .5);
}

void GameState::getInput()
{
	//Camera
	OIS::Keyboard *lKeyboard = OgreFramework::getSingletonPtr()->m_pKeyboard;
	if (lKeyboard->isKeyDown(OIS::KC_A))
		m_TranslateVector.x = -m_MoveScale;

	if (lKeyboard->isKeyDown(OIS::KC_D))
		m_TranslateVector.x = m_MoveScale;

	if (lKeyboard->isKeyDown(OIS::KC_W))
		m_TranslateVector.z = -m_MoveScale;

	if (lKeyboard->isKeyDown(OIS::KC_S))
		m_TranslateVector.z = m_MoveScale;

	if (lKeyboard->isKeyDown(OIS::KC_Q))
		m_TranslateVector.y = -m_MoveScale;

	if (lKeyboard->isKeyDown(OIS::KC_E))
		m_TranslateVector.y = m_MoveScale;
}

void GameState::update(double timeSinceLastFrame)
{
    m_FrameEvent.timeSinceLastFrame = timeSinceLastFrame;
	
    if(quit == true)
    {
        popAppState();
        return;
    }
	
	if (socketOK)
	{
		if (!cb_read->isFull())
		{
			socket->socketFD_ZERO(&fd_read);
			socket->socketFD_ZERO(&fd_write);
			socket->socketFD_SET(&fd_read);
			socket->socketFD_SET(&fd_write);
			socket->socketSelect(&fd_read, &fd_write);
			if (FD_ISSET(socket->getSock(), &fd_read))
			{
				Ogre::String msg;
				socket->socketRead(msg, cb_read->getEmptySize());
				OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [RAW Internet] : ").append(msg));
				cb_read->putInBuffer(msg);
			}
		}
		if (cb_read->getSize() > 0)
		{
			Ogre::String cmd(cb_read->getLine());
			OgreFramework::getSingletonPtr()->m_pLog->logMessage(Ogre::String("<<< [Internet] : ").append(cmd));
			quit = Protocole::getSingletonPtr()->parseMsg(cmd);
		}
	}

	m_MoveScale = m_MoveSpeed   * timeSinceLastFrame;
	m_RotScale = m_RotateSpeed * timeSinceLastFrame;

	m_TranslateVector = Ogre::Vector3::ZERO;

    getInput();
    moveCamera();
}

void GameState::buildGUI()
{
    
}
