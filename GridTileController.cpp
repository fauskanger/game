#include "GridTileController.h"


GridTileController::GridTileController()
{
	numberOfTiles = 1;
	tiles = new GridTile*[numberOfTiles];
	tiles[0] = new GridTile();
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