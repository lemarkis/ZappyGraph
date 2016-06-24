#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <OgreSubEntity.h>
#include <OgreMaterialManager.h>

#include "Framework\AppState.hpp"
#include "Network\Socket.hpp"
#include "Network\Protocole.hpp"
#include "Network\CircularBuffer.hpp"

class GameState : public AppState
{
public:
	GameState();

	DECLARE_APPSTATE_CLASS(GameState)

	void enter();
	void createScene();
	void exit();
	bool pause();
	void resume();

	void moveCamera();
	void getInput();
    void buildGUI();

	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);

	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	void onLeftPressed(const OIS::MouseEvent &evt);

	void update(double timeSinceLastFrame);

private:
	bool quit;
	Ogre::FrameEvent frameEvent;

	Ogre::SceneManager * sceneMgr;
	Ogre::Camera * camera;

	Socket * socket;
	bool socketOK;
	CircularBuffer * cb_read;
	fd_set fd_read, fd_write;

	Ogre::Vector3				m_TranslateVector;
	Ogre::Real					m_MoveSpeed;
	Ogre::Degree				m_RotateSpeed;
	float						m_MoveScale;
	Ogre::Degree				m_RotScale;

};

#endif
