#include "GridTile.h"


GridTile::GridTile()
{
	//this->polygonType = pt;

	generateShape(); 

	int b = 8;
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
	
		gtShape = new GridTileShape();
	/*switch(polygonType)
	{
	case GridTileController::PENTAGON:
		shape = (new GridTileShape())->getShape();
		break;
	default:
		shape = new sf::RectangleShape(sf::Vector2f(100,100));
		break;
	}*/
}
