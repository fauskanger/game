#include "myAnimation.h"
/*
	Requires the path to be path/to/images/name0"minValue".png - path/to/images/name0"maxValue".png, 
	and each path much have the exact same string length. That is, insert zeroes before image number when necessary.

	(.png not required; any filetype accepted by sf::Texture will be fine.)
*/

	myAnimation::myAnimation(int minValue, int maxValue, sf::String pathToBeforeNumber, sf::String afterNumberString, int startFrame, int originX, int originY)
	{
		this->minValue = minValue;
		this->maxValue = maxValue;
		this->currentFrame = startFrame;

		textures = new sf::Texture[maxValue-minValue+1];
		
		int maxNumLength = (maxValue!=0)? log10(float(maxValue))+1: 1;
		int numLength;
		sf::String fillZeroes = "";
		sf::String filePath;

		std::cout << std::string("Loading animation images in " + pathToBeforeNumber + "##" + afterNumberString) << std::endl;

		for(int i=minValue; i<=maxValue; i++)
		{
			numLength = (i!=0)? log10(float(i))+1: 1;
			fillZeroes = "";
			for(int f=numLength; f<maxNumLength; f++)
				fillZeroes += "0";
			
			filePath = pathToBeforeNumber + fillZeroes + std::to_string(long double(i)) + afterNumberString;
			//std::cout << std::string(filePath) << std::endl;
			textures[i-minValue].loadFromFile(filePath);

		}
		
		sprite = new sf::Sprite();
		sprite->setTexture(textures[currentFrame]);
		sprite->setOrigin(originX, originY);
	};
	
	void myAnimation::setPosition(int x, int y)
	{
		sprite->setPosition(x, y);
	};

	void myAnimation::setSpriteTexture(sf::Texture* texture)
	{		
		sprite->setTexture(*texture);
	};

	void myAnimation::setSpriteTexture(int texFrame)
	{		
		texFrame = (texFrame>maxValue || texFrame<minValue)? minValue: texFrame;
		sprite->setTexture(textures[texFrame-minValue]);
	};


	void myAnimation::setTextures(sf::Texture* textures)
	{		
		this->textures=textures;
	};


	void myAnimation::setToPreviousFrame(int from)
	{
		setCurrentFrame(getPreviousFrame(from));
	};
	void myAnimation::setToNextFrame(int from)
	{
		setCurrentFrame(getNextFrame(from));
	};

	int myAnimation::getPreviousFrame(int from)
	{
		from = (from<0)? currentFrame: from;
		return (from>minValue)? from-1: maxValue;
	};
	int myAnimation::getNextFrame(int from)
	{
		from = (from<0)? currentFrame: from;
		return (from<maxValue-minValue)? from+1: minValue;
	};


	void myAnimation::setCurrentFrame(int frameNumber)
	{
		currentFrame = (frameNumber>maxValue || frameNumber<minValue)? minValue: frameNumber;
		setSpriteTexture(currentFrame);
	}

	sf::Sprite* myAnimation::getSprite()
	{
		return sprite;
	}
	int myAnimation::getCurrentFrame()
	{
		return currentFrame;
	};


	myAnimation::~myAnimation()
	{
		delete textures,sprite;
	};
