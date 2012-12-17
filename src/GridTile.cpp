#include "GridTile.h"


GridTile::GridTile(Globals::PolygonType polygonType)
{
	this->polygonType = polygonType;

	generateShape(); 
}


GridTile::~GridTile(void)
{
}


sf::Shape* GridTile::getShape()
{
	return gtShape->getShape();
}


void GridTile::generateShape()
{
	switch(polygonType)
	{
	case Globals::PENTAGON:
		gtShape = new GridTileShape();
		gtShape->getShape()->setOutlineThickness(2);
		gtShape->getShape()->setFillColor(sf::Color::Transparent);
		break;
	default:
		gtShape = new GridTileShape();
		break;
	}
}

bool GridTile::hasPoint(float x, float y)
{
	return gtShape->hasPoint(x,y);
}
