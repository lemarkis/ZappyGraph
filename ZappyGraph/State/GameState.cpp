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
}

void GameState::createScene()
{
    sceneMgr->createLight("Light")->setPosition(75,75,75);

}

bool GameState::keyPressed(const OIS::KeyEvent &keyEventRef)
{
    return true;
}

bool GameState::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    OgreFramework::getSingletonPtr()->keyPressed(keyEventRef);
    return true;
}

bool GameState::mouseMoved(const OIS::MouseEvent &evt)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseMove(evt)) return true;

	return true;
}

bool GameState::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseDown(evt, id)) return true;

    return true;
}

bool GameState::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(OgreFramework::getSingletonPtr()->m_pTrayMgr->injectMouseUp(evt, id)) return true;

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
    OgreFramework::getSingletonPtr()->m_pTrayMgr->frameRenderingQueued(m_FrameEvent);

    if(quit == true)
    {
        popAppState();
        return;
    }

    getInput();
    moveCamera();
}

void GameState::buildGUI()
{
    
}
