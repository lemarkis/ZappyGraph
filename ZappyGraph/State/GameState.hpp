#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <OgreSubEntity.h>
#include <OgreMaterialManager.h>

#include "Framework\AppState.hpp"

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

};

#endif
