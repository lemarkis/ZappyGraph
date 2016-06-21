#include "MenuState.hpp"

MenuState::MenuState()
{
    m_bQuit         = false;
    m_FrameEvent    = Ogre::FrameEvent();
}

void MenuState::enter()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Entering MenuState...");

    m_pSceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->createSceneManager(Ogre::ST_GENERIC, "MenuSceneMgr");
    m_pSceneMgr->setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));

    m_pSceneMgr->addRenderQueueListener(OgreFramework::getSingletonPtr()->m_pOverlaySystem);

    m_pCamera = m_pSceneMgr->createCamera("MenuCam");
    m_pCamera->setPosition(Ogre::Vector3(0, 25, -50));
    m_pCamera->lookAt(Ogre::Vector3(0, 0, 0));
    m_pCamera->setNearClipDistance(1);

    m_pCamera->setAspectRatio(Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth()) /
        Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight()));

    OgreFramework::getSingletonPtr()->m_pViewport->setCamera(m_pCamera);

    OgreFramework::getSingletonPtr()->m_pTrayMgr->destroyAllWidgets();
	OgreFramework::getSingletonPtr()->m_pTrayMgr->showCursor();
    
	m_InputTxt = OgreFramework::getSingletonPtr()->m_pTrayMgr->createLabel(OgreBites::TL_NONE, "InputTxt", "Enter IP:port", 250);
	m_InputTxt->getOverlayElement()->setPosition(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth() * 0.15, OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight() * 0.45);
	Ogre::OverlayElement * conect = OgreFramework::getSingletonPtr()->m_pTrayMgr->createButton(OgreBites::TL_NONE, "EnterBtn", "Connect", 250)->getOverlayElement();
	conect->setPosition(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth() * 0.15, OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight() * 0.5);
	Ogre::OverlayElement * exit = OgreFramework::getSingletonPtr()->m_pTrayMgr->createButton(OgreBites::TL_NONE, "ExitBtn", "Quit", 250)->getOverlayElement();
	exit->setPosition(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth() * 0.15, OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight() * 0.55);
    Ogre::OverlayElement * title = OgreFramework::getSingletonPtr()->m_pTrayMgr->createLabel(OgreBites::TL_NONE, "MenuLbl", "ZappyGraph", 250)->getOverlayElement();
	title->setPosition(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth() * 0.5 - 125, OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight() * 0.02);
	OgreFramework::getSingletonPtr()->m_pTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    createScene();
}

void MenuState::createScene()
{
}

void MenuState::exit()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Leaving MenuState...");

    m_pSceneMgr->destroyCamera(m_pCamera);
    if(m_pSceneMgr)
        OgreFramework::getSingletonPtr()->m_pRoot->destroySceneManager(m_pSceneMgr);

    OgreFramework::getSingletonPtr()->m_pTrayMgr->clearAllTrays();
    OgreFramework::getSingletonPtr()->m_pTrayMgr->destroyAllWidgets();
    OgreFramework::getSingletonPtr()->m_pTrayMgr->setListener(0);
}

bool MenuState::keyPressed(const OIS::KeyEvent &keyEventRef)
{
    if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_ESCAPE))
    {
        m_bQuit = true;
        return true;
    }

	if (((keyEventRef.text >= 48 && keyEventRef.text <= 58) || keyEventRef.text == 46) && m_InputTxt->getCaption().size() < 21)
	{
		Ogre::String ip(m_InputTxt->getCaption());
		if (!ip.compare("Invalid IP") || !ip.compare("Enter IP:port"))
		{
			ip.clear();
		}
		char c = keyEventRef.text;
		Ogre::String tmp(1, c);
		ip.append(tmp);
		m_InputTxt->setCaption(ip);
	}

	if (keyEventRef.text == 8 && m_InputTxt->getCaption().size() > 0)
	{
		Ogre::String ip(m_InputTxt->getCaption());
		ip.erase(ip.end() - 1);
		m_InputTxt->setCaption(ip);
	}
	if (keyEventRef.key == OIS::KC_RETURN)
	{
		Ogre::String input = m_InputTxt->getCaption();
		if (!std::regex_match(input, std::regex("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}:[0-9]{1,5}")))
		{
			m_InputTxt->setCaption("Invalid IP");
		}
		else
		{
			IPConnect::getSingletonPtr()->ipPort = input;
			changeAppState(findByName("GameState"));
		}
	}

    OgreFramework::getSingletonPtr()->keyPressed(keyEventRef);
    return true;
}

bool MenuState::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    OgreFramework::getSingletonPtr()->keyReleased(keyEventRef);
    return true;
}

bool MenuState::mouseMoved(const OIS::MouseEvent &evt)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseMove(evt)) return true;
    return true;
}

bool MenuState::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseDown(evt, id)) return true;
    return true;
}

bool MenuState::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseUp(evt, id)) return true;
    return true;
}

void MenuState::update(double timeSinceLastFrame)
{
    m_FrameEvent.timeSinceLastFrame = timeSinceLastFrame;
    OgreFramework::getSingletonPtr()->m_pTrayMgr->frameRenderingQueued(m_FrameEvent);

    if(m_bQuit == true)
    {
        shutdown();
        return;
    }
}

void MenuState::buttonHit(OgreBites::Button *button)
{
    if(button->getName() == "ExitBtn")
        m_bQuit = true;
	else if (button->getName() == "EnterBtn")
	{
		Ogre::String input = m_InputTxt->getCaption();
		if (!std::regex_match(input, std::regex("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}:[0-9]{1,5}")))
		{
			m_InputTxt->setCaption("Invalid IP");
		}
		else
		{
			IPConnect::getSingletonPtr()->ipPort = input;
			changeAppState(findByName("GameState"));
		}
	}
}
