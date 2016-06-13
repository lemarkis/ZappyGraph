//|||||||||||||||||||||||||||||||||||||||||||||||

#ifndef ZAPPYGRAPH_HPP
#define ZAPPYGRAPH_HPP

//|||||||||||||||||||||||||||||||||||||||||||||||

#include "AdvancedOgreFramework.hpp"
#include "AppStateManager.hpp"

//|||||||||||||||||||||||||||||||||||||||||||||||

class ZappyGraph
{
public:
	ZappyGraph();
	~ZappyGraph();

	void startZappyGraphicalClient();

private:
	AppStateManager*	m_pAppStateManager;
};

//|||||||||||||||||||||||||||||||||||||||||||||||

#endif

//|||||||||||||||||||||||||||||||||||||||||||||||