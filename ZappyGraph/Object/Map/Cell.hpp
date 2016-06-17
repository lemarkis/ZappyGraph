#ifndef CELL_HPP
#define CELL_HPP

#include <Ogre.h>

class Cell
{
public:
	Cell(Ogre::SceneManager * pSceneMgr);
	~Cell();

	Ogre::SceneNode * getNode() const;

protected:
	Ogre::SceneNode * node;

};

#endif // !CELL_HPP
