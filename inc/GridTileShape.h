#pragma once
#include <SFML\Graphics.hpp>

class GridTileShape
{
private:	
	bool isPointInTriangle(sf::Vector2f p, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
	bool isSameSideOfLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f a, sf::Vector2f b);
public:
	static const int pentagonPt0X = 40;
	static const int pentagonPt0Y = 0;
	static const int pentagonPt1X = 80;
	static const int pentagonPt1Y = 20;
	static const int pentagonPt2X = 60;
	static const int pentagonPt2Y = 60;
	static const int pentagonPt3X = 20;
	static const int pentagonPt3Y = 60;
	static const int pentagonPt4X = 0;
	static const int pentagonPt4Y = 20;

	GridTileShape(void);
	~GridTileShape(void);
	
	bool hasPoint(float x, float y);
	sf::Shape* getShape();
	sf::ConvexShape* shape;

};

