#include "GridFloor.h"



GridFloor::GridFloor(sf::RenderWindow* window, int nX, int nY, GridTileController* gtc)
{
	this->window = window;
	numCols = nX;
	numRows = nY;
	this->gtc = gtc;
	this->gtc->initializeTiles(nX*nY);
}


GridFloor::~GridFloor(void)
{
	delete tileList;
}

void GridFloor::draw()
{
	for(int i=0; i<gtc->getNumberOfTiles(); i++)
	{
		window->draw( *(gtc->getTile(i)->getShape()) );
	}
}
