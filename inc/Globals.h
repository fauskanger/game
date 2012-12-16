#pragma once
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>

class Globals;
class Globals
{
private:
	sf::SoundBuffer** sounds;
	sf::Sound* sound;
public:

	// Constants:
	static const int FRAMERATE = 120;
	static enum SoundNames {HappyHit, SadHit};
	static enum PolygonType {TRIANGLE, SQUARE, PENTAGON, HEXAGON};
	// 14 known pentagon tiling patterns: http://www.mathpuzzle.com/tilepent.html
	// See also: http://boardgamegeek.com/thread/534988/something-that-has-bugged-me-for-oh-well-overn/

	
	sf::Clock* gameClock;

	Globals(void) 
	{
		gameClock = new sf::Clock();

		int numberOfSounds = 2;
		sounds = new sf::SoundBuffer*[numberOfSounds];
		for(int i=0; i<numberOfSounds; i++)
		{
			sounds[i] = new sf::SoundBuffer();
		}
		sounds[0]->loadFromFile("sound/HappyHit.wav");
		sounds[1]->loadFromFile("sound/SadHit.wav");
		
		sound = new sf::Sound();
	}


	sf::Sound* getSound(int index)
	{
		sound->setBuffer(*sounds[index]);
		return sound;
	}



	~Globals(void)
	{
		delete gameClock;
	}
};

