#pragma once
#include <SFML\Graphics.hpp>

class GridTileShape
{
public:
	GridTileShape(void);
	~GridTileShape(void);
	
	bool hasPoint(float x, float y);
	sf::ConvexShape* getShape();
	sf::ConvexShape* shape;

};

