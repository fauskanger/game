#include "GridTileShape.h"


GridTileShape::GridTileShape(void)
{
	shape = new sf::ConvexShape();
	shape->setPointCount(5);
	shape->setPoint(0, sf::Vector2f(pentagonPt0X, pentagonPt0Y));
	shape->setPoint(1, sf::Vector2f(pentagonPt1X, pentagonPt1Y));
	shape->setPoint(2, sf::Vector2f(pentagonPt2X, pentagonPt2Y));
	shape->setPoint(3, sf::Vector2f(pentagonPt3X, pentagonPt3Y));
	shape->setPoint(4, sf::Vector2f(pentagonPt4X, pentagonPt4Y));
}


GridTileShape::~GridTileShape(void)
{
	delete shape;
}


sf::Shape* GridTileShape::getShape()
{
	return shape;
}

bool GridTileShape::hasPoint(float x, float y)
{
	return false;
}

bool GridTileShape::isSameSideOfLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f a, sf::Vector2f b)
{
	return false;
}

bool GridTileShape::isPointInTriangle(sf::Vector2f p, sf::Vector2f a, sf::Vector2f b,  sf::Vector2f c)
{
	return false;
}
//Function pointintriangle(px#,py#,ax#,ay#,bx#,by#,cx#,cy#)
//	If sameside(px,py,ax,ay,bx,by,cx,cy) And sameside(px,py,bx,by,ax,ay,cx,cy) And sameside(px,py,cx,cy,ax,ay,bx,by)
//		Return True
//	Else
//		Return False
//	EndIf
//End Function
