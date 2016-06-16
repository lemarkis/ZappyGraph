#include "PauseState.hpp"

PauseState::PauseState()
{
    m_bQuit             = false;
    m_FrameEvent        = Ogre::FrameEvent();
}

void PauseState::enter()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Entering PauseState...");

    m_pSceneMgr = OgreFramework::getSingletonPtr()->m_pRoot->createSceneManager(Ogre::ST_GENERIC, "PauseSceneMgr");
    m_pSceneMgr->setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));

	m_pSceneMgr->addRenderQueueListener(OgreFramework::getSingletonPtr()->m_pOverlaySystem);

    m_pCamera = m_pSceneMgr->createCamera("PauseCam");
    m_pCamera->setPosition(Ogre::Vector3(0, 25, -50));
    m_pCamera->lookAt(Ogre::Vector3(0, 0, 0));
    m_pCamera->setNearClipDistance(1);

    m_pCamera->setAspectRatio(Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth()) /
        Ogre::Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight()));

    OgreFramework::getSingletonPtr()->m_pViewport->setCamera(m_pCamera);

    m_bQuit = false;

    createScene();
}

void PauseState::createScene()
{
}

void PauseState::exit()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Leaving PauseState...");

    m_pSceneMgr->destroyCamera(m_pCamera);
    if(m_pSceneMgr)
        OgreFramework::getSingletonPtr()->m_pRoot->destroySceneManager(m_pSceneMgr);
}

bool PauseState::keyPressed(const OIS::KeyEvent &keyEventRef)
{
    if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_ESCAPE))
    {
        m_bQuit = true;
        return true;
    }

    OgreFramework::getSingletonPtr()->keyPressed(keyEventRef);

    return true;
}

bool PauseState::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    OgreFramework::getSingletonPtr()->keyReleased(keyEventRef);

    return true;
}

bool PauseState::mouseMoved(const OIS::MouseEvent &evt)
{
    return true;
}

bool PauseState::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    return true;
}

bool PauseState::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    return true;
}

void PauseState::update(double timeSinceLastFrame)
{
    m_FrameEvent.timeSinceLastFrame = timeSinceLastFrame;

    if(m_bQuit == true)
    {
        popAppState();
        return;
    }
}
