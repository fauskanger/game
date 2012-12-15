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
		break;
	default:
		gtShape = new GridTileShape();
		break;
	}
}
