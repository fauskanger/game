#pragma once
#include <SFML\Graphics.hpp>

#include "GridTileController.h"

class GridTile
{
private:
	sf::Shape* shape;
	GridTileController::PolygonType polygonType;
	void generateShape();

public:
	GridTile(GridTileController::PolygonType pt);
	~GridTile(void);

	sf::Shape* getShape();
};

