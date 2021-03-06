#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <regex>

#include "Framework\AppState.hpp"
#include "Object\ObjectFactory.hpp"

class MenuState : public AppState
{
public:
    MenuState();

	DECLARE_APPSTATE_CLASS(MenuState)

	void enter();
	void createScene();
	void exit();

	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);

	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

	void update(double timeSinceLastFrame);

	void buttonHit(OgreBites::Button * button);

private:
	bool                        m_bQuit;
	OgreBites::Label *			m_InputTxt;
};

#endif
