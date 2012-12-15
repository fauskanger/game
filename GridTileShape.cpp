#include "GridTileShape.h"


GridTileShape::GridTileShape(void)
{
	shape = new sf::ConvexShape();
	shape->setPointCount(5);
	shape->setPoint(0,sf::Vector2f(0,0));
	shape->setPoint(1,sf::Vector2f(0,20));
	shape->setPoint(2,sf::Vector2f(10,50));
	shape->setPoint(3,sf::Vector2f(60,60));
	shape->setPoint(4,sf::Vector2f(40,10));
}


GridTileShape::~GridTileShape(void)
{
	delete shape;
}


sf::ConvexShape* GridTileShape::getShape()
{
	return shape;
}
