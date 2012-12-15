#include "GridTileController.h"


GridTileController::GridTileController(PolygonType polygonType)
{
	this->polygonType = polygonType;
	numberOfTiles = 0;
	isInitialized = false;
}


GridTileController::~GridTileController(void)
{
}

void GridTileController::initializeTiles(int numberOfTiles)
{
	this->numberOfTiles = numberOfTiles;
	tiles = new GridTile*[numberOfTiles];
	for (int i=0; i<numberOfTiles; i++)
	{
		tiles[i] = new GridTile();
	}
	isInitialized = true;
}

GridTile* GridTileController::getTile(int index)
{
	if(!isInitialized)
	{
		std::cout << "The GridTileController has not been initialized! (No tiles available.)" << std::endl;
		return NULL;
	}
	return tiles[index];
}

int GridTileController::getNumberOfTiles()
{
	return numberOfTiles;
}