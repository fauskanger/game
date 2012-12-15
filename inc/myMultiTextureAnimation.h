#pragma once
#include "myAnimation.h"

class myMultiTextureAnimation
{
private:
	myAnimation** textureAnimations;
	int* currentTex;
	int numTexs;
public:
	myMultiTextureAnimation(int numTexs, myAnimation** textureAnimations);

	void setPosition(int x, int y);	
	void setTexture(int tex);
	int getTextureIndex();
	sf::Sprite* getSprite();
	void next();
	void previous();
	int getCurrentFrame();
	
	void rotate(float angle);
	void setOrigin(float x_and_y);
	void setOrigin(float x, float y);
	void setOrigin(sf::Vector2f origin);
	void move(sf::Vector2f moveVector);
	void move(float x, float y);
	void scale(sf::Vector2f scaleVector);
	void scale(float x, float y);

	~myMultiTextureAnimation();
};

