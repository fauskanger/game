
/*
	Requires the path to be path/to/images/name0"minValue".png - path/to/images/name0"maxValue".png, 
	and each path much have the exact same string length. That is, insert zeroes before image number when necessary.

	(.png not required; any filetype accepted by sf::Texture will be fine.)
*/
#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class myAnimation {
private:
	int minValue, maxValue, currentFrame;
	sf::Texture* textures;
	sf::Sprite* sprite;
	void setSpriteTexture(int texFrame);
public:
	myAnimation(int minValue, int maxValue, sf::String pathToBeforeNumber, sf::String afterNumberString, int startFrame=0, int originX=0, int originY=0);
	
	void setPosition(int x, int y);
	void setSpriteTexture(sf::Texture* texture);
	void setTextures(sf::Texture* textures);
	void setToPreviousFrame(int from=-1);
	void setToNextFrame(int from=-1);
	int getPreviousFrame(int from=-1);
	int getNextFrame(int from=-1);
	void setCurrentFrame(int frameNumber);
	sf::Sprite* getSprite();
	int getCurrentFrame();

	~myAnimation();
};