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
	Globals::PolygonType polygonType;
	GridTile** tiles;
	int numberOfTiles;

	void initializeTiles(int numberOfTiles);
	GridTile* getTile(int index);
	int getNumberOfTiles();

	GridTileController(Globals::PolygonType polygonType);
	~GridTileController(void);

};

