#include "myMultiTextureAnimation.h"


	myMultiTextureAnimation::myMultiTextureAnimation(int numTexs, myAnimation** textureAnimations)
	{
		this->textureAnimations = new myAnimation*[numTexs];
		this->textureAnimations = textureAnimations;
		this->numTexs = numTexs;
		currentTex = new int;
		*currentTex = textureAnimations[0]->getCurrentFrame();
	};

	
	void myMultiTextureAnimation::setPosition(int x, int y)
	{
		textureAnimations[getTextureIndex()]->setPosition(x,y);
	};

	void myMultiTextureAnimation::setTexture(int tex)
	{
		textureAnimations[tex]->setCurrentFrame(getCurrentFrame());
		*currentTex = tex;
	};

	int myMultiTextureAnimation::getTextureIndex()
	{
		return *currentTex;
	};

	sf::Sprite* myMultiTextureAnimation::getSprite()
	{
		return textureAnimations[*currentTex]->getSprite();
	};

	void myMultiTextureAnimation::next()
	{
		textureAnimations[*currentTex]->setToNextFrame(getCurrentFrame());
	};

	void myMultiTextureAnimation::previous()
	{
		textureAnimations[*currentTex]->setToPreviousFrame(getCurrentFrame());
	};

	int myMultiTextureAnimation::getCurrentFrame()
	{
		return textureAnimations[*currentTex]->getCurrentFrame();
	};

	myMultiTextureAnimation::~myMultiTextureAnimation()
	{
		delete[] currentTex, textureAnimations;
	};

	



	void myMultiTextureAnimation::rotate(float angle)
	{
		for(int i=0; i<numTexs; i++)
			textureAnimations[i]->getSprite()->rotate(angle);
	}

	void myMultiTextureAnimation::move(sf::Vector2f moveVector)
	{
		for(int i=0; i<numTexs; i++)
			textureAnimations[i]->getSprite()->move(moveVector);
	}

	void myMultiTextureAnimation::scale(sf::Vector2f scaleVector)
	{
		for(int i=0; i<numTexs; i++)
			textureAnimations[i]->getSprite()->scale(scaleVector);
	}

	void myMultiTextureAnimation::move(float x, float y)
	{
		move(sf::Vector2f(x,y));
	}

	void myMultiTextureAnimation::scale(float x, float y)
	{
		scale(sf::Vector2f(x,y));
	}


	
	
	
	void myMultiTextureAnimation::setOrigin(sf::Vector2f origin)
	{
		for(int i=0; i<numTexs; i++)
			textureAnimations[i]->getSprite()->setOrigin(origin);
	};
	
	void myMultiTextureAnimation::setOrigin(float x, float y)
	{
		setOrigin(sf::Vector2f(x,y));
	};

	void myMultiTextureAnimation::setOrigin(float xandy)
	{
		setOrigin(sf::Vector2f(xandy,xandy));
	};