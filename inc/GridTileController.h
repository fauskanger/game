#pragma once
#include "GridTile.h"
#include <iostream>


class GridTile;

class GridTileController
{
private:
	bool isInitialized;
public: 
	enum PolygonType {TRIANGLE, SQUARE, PENTAGON, HEXAGON};
	// 14 known pentagon tiling patterns: http://www.mathpuzzle.com/tilepent.html
	// See also: http://boardgamegeek.com/thread/534988/something-that-has-bugged-me-for-oh-well-overn/

	PolygonType polygonType;
	GridTile** tiles;
	int numberOfTiles;

	void initializeTiles(int numberOfTiles);
	GridTile* getTile(int index);
	int getNumberOfTiles();

	GridTileController(PolygonType polygonType);
	~GridTileController(void);

};

