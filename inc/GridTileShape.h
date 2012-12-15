#pragma once
#include <SFML\Graphics.hpp>

class GridTileShape
{
public:
	GridTileShape(void);
	~GridTileShape(void);

	sf::ConvexShape* getShape();
	sf::ConvexShape* shape;

};

