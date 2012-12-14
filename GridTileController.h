#pragma once
#include "GridTile.h"
#include "GridTileShape.h"

class GridTileController
{
public: 
	enum PolygonType {TRIANGLE, SQUARE, PENTAGON, HEXAGON};

	GridTileController::PolygonType nGon;
	GridTile** tiles;
	int numberOfTiles;


	GridTile* getTile(int index);
	int getNumberOfTiles();

	GridTileController(PolygonType nGon=PolygonType::HEXAGON);
	~GridTileController(void);

};

