#include "GridTile.h"


GridTile::GridTile(GridTileController::PolygonType pt)
{
	this->polygonType = pt;
	generateShape(); 
}


GridTile::~GridTile(void)
{
}


sf::Shape* GridTile::getShape()
{
	return shape;
}


void GridTile::generateShape()
{
	switch(polygonType)
	{
	case GridTileController::PENTAGON:
		shape = (new GridTileShape())->getShape();
		break;
	default:
		shape = new sf::RectangleShape(sf::Vector2f(100,100));
		break;
	}
}
