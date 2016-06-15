#ifndef SPLASHSCREEN_STATE_HPP
#define SPLASHSCREEN_STATE_HPP

#include "Framework\AppState.hpp"
#include "Framework\BetaGUI.hpp"
#include "Object\CacheObject.hpp"

class SplashScreenState : public AppState
{
public:
	SplashScreenState();

	DECLARE_APPSTATE_CLASS(SplashScreenState)

	void enter();
	void createScene();
	void exit();

	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);

	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

	void update(double timeSinceLastFrame);

private:
	bool                        m_bQuit;
	BetaGUI::GUI *				m_pGUI;
};

#endif
