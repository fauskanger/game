#pragma once
#include <SFML\Graphics.hpp>

#include "GridTileController.h"
#include "GridTileShape.h"


class GridTile
{
private:
	sf::Shape* shape;
//	GridTileController::PolygonType polygonType;
	void generateShape();

public:
	GridTile(void);
	~GridTile(void);

	sf::Shape* getShape();
};

