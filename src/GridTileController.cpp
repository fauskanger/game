#include "GridTileController.h"


GridTileController::GridTileController(Globals::PolygonType polygonType)
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
		tiles[i] = new GridTile(polygonType);
	}
	setTilePositions();
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

void GridTileController::setTilePositions()
{	
	int x=0, y=0;

	for (int i=0; i<numberOfTiles; i++)
	{
		tiles[i]->getShape()->move(x+=30,y+=30);
	}
}

GridTile* GridTileController::getHoveredTile(float x, float y)
{	
	GridTile* ret = NULL;

	for (int i=0; i<numberOfTiles; i++)
	{
		if (tiles[i]->hasPoint(x,y))
		{
			ret = tiles[i];
			break;
		}
	}

	return ret;
}