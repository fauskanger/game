#pragma once
#include "GridTile.h"
#include "GridTileShape.h"

class GridTileController
{
public: 
	enum PolygonType {TRIANGLE, SQUARE, PENTAGON, HEXAGON};
	// 14 known pentagon tiling patterns: http://www.mathpuzzle.com/tilepent.html

	GridTileController::PolygonType nGon;
	GridTile** tiles;
	int numberOfTiles;


	GridTile* getTile(int index);
	int getNumberOfTiles();

	GridTileController(PolygonType nGon=PolygonType::HEXAGON);
	~GridTileController(void);

};

