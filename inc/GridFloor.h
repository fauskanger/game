#pragma once
#include <SFML\Graphics.hpp>
#include "GridTileController.h"

class GridFloor
{
private:
	sf::RenderWindow* window;
	int numCols,numRows,borderWith;
	GridTile** tileList;
	GridTileController* gtc;

public:
	void draw();
	GridFloor(sf::RenderWindow* window, int nX, int nY, GridTileController* gtc);
	~GridFloor(void);
};

