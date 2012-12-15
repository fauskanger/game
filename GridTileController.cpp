#include "GridTileController.h"


GridTileController::GridTileController()
{
	numberOfTiles = 1;
	tiles = new GridTile*[numberOfTiles];
	// TODO: initialize *tiles
	GridTile* gt = new GridTile();
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