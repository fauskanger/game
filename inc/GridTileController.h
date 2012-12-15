#pragma once
#include <iostream>

#include "GridTile.h"
#include "Globals.h"

class GridTile;

class GridTileController
{
private:
	bool isInitialized;
	void setTilePositions();
public: 
	// 14 known pentagon tiling patterns: http://www.mathpuzzle.com/tilepent.html
	// See also: http://boardgamegeek.com/thread/534988/something-that-has-bugged-me-for-oh-well-overn/

	Globals::PolygonType polygonType;
	GridTile** tiles;
	int numberOfTiles;

	void initializeTiles(int numberOfTiles);
	GridTile* getTile(int index);
	int getNumberOfTiles();

	GridTileController(Globals::PolygonType polygonType);
	~GridTileController(void);

};

