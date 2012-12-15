#pragma once
#include <SFML\Graphics.hpp>

#include "GridTileController.h"
#include "GridTileShape.h"

class GridTileController;

class GridTile
{
private:
	GridTileShape* gtShape;
	GridTileController::PolygonType polygonType;
	void generateShape();

public:
	GridTile(void);
	~GridTile(void);

	sf::Shape* getShape();
};

