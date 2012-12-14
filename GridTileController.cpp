#include "GridTileController.h"


GridTileController::GridTileController(GridTileController::PolygonType nGon)
{
	this->nGon = nGon;
	numberOfTiles = 1;
	tiles = new GridTile*[numberOfTiles];
	tiles[0] = new GridTile(nGon);
}


GridTileController::~GridTileController(void)
{
}


GridTile* GridTileController::getTile(int index)
{
	return tiles[index];
}

int GridTileController::getNumberOfTiles()
{
	return numberOfTiles;
}