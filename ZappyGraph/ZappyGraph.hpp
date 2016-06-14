//|||||||||||||||||||||||||||||||||||||||||||||||

#ifndef ZAPPYGRAPH_HPP
#define ZAPPYGRAPH_HPP

//|||||||||||||||||||||||||||||||||||||||||||||||

#include "Framework\AdvancedOgreFramework.hpp"
#include "Framework\AppStateManager.hpp"

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