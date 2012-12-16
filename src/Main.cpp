// Libraries
#include "Main.h"


// Global variables, functions, classes


void testKey(sf::Keyboard::Key, bool*, const sf::Event);
void testMouse(sf::Mouse::Button, bool*, const sf::Event);

void testKey(sf::Keyboard::Key keyType, bool* buttonBool, const sf::Event event)
{
	if (event.type == sf::Event::KeyPressed  &&  event.key.code == keyType) 
	{
		*buttonBool = true;
	}

	if (event.type == sf::Event::KeyReleased  &&  event.key.code == keyType) 
	{
		*buttonBool = false;
	}
}

void testMouse(sf::Mouse::Button button, bool* buttonBool, const sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == button) 
	{
		*buttonBool = true;
	}

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == button) 
	{
		*buttonBool = false;
	}
}

/*
	Convenient int/float/double/.../ to string converter
*/
template<typename Ty>
std::string to_string(const Ty& obj)
{
    std::ostringstream buffer;
    buffer << obj;
    return buffer.str();
} 

/*
	Return an sf::Color with getColor(). Calling iterate() will fluently increment or decrement the color's rgb values.
*/
class myColorIterator {
	private:
		sf::Color* color;
		int lowThresh;
		int highThresh;
		int factor;

		void init(int colorSteps, int lowThresh, int highThresh)
		{
			this->lowThresh = lowThresh;
			this->highThresh = highThresh;
			this->factor = colorSteps;
			this->color = new sf::Color;
		};

	public:
		sf::Color getColor()
		{
			return *color;
		};		

		void iterate()
		{
			if (factor<0)
			{				
				color->g = (color->g > lowThresh)?							color->g+factor: color->g;
				color->r = (color->r > lowThresh && color->g==lowThresh)?	color->r+factor: color->r;
				color->b = (color->b > lowThresh && color->r==lowThresh)?	color->b+factor: color->b;
			}
			else
			{				
				color->r = (color->r < highThresh)?							color->r+factor: color->r;
				color->g = (color->g < highThresh && color->r==highThresh)? color->g+factor: color->g;
				color->b = (color->b < highThresh && color->g==highThresh)? color->b+factor: color->b;
			}
			if((factor>0 && color->r >= highThresh && color->g >= highThresh && color->b >= highThresh) || (factor<0 && color->r <= lowThresh && color->g <= lowThresh && color->b <= lowThresh))
			{
				factor = -factor;
			}
		};

		void setColorSteps(int colorSteps)
		{
			this->factor = (factor>0 && colorSteps>0)? colorSteps: -colorSteps;
		};

		void setThresh(int high, int low)
		{
			this->highThresh = high;
			this->lowThresh  = low;
		};

		myColorIterator(int r=255, int g=255, int b=255, int colorSteps=1, int lowThresh = 40, int highThresh = 215)
		{
			init(colorSteps,lowThresh,highThresh);
			color->r = r;
			color->b = b;
			color->g = g;
		};

		myColorIterator(sf::Color color)
		{
			myColorIterator(color.r,color.g,color.b);
		};

		~myColorIterator()
		{
			delete color;
		};
};







// Main		///////////////////////////////////////////////////////////////////////////////////////

int main() 
{
	if(!isDebug)	FreeConsole();	// Hide console when releasing


	// CREATION:

	// Init Globals:
	Globals* globals = new Globals();
	
	// Animation:
	myAnimation* blueAnimation = new myAnimation(0,118,"img/animation/Blue/BlueNoWand_00",".png",0);
	myAnimation* redAnimation = new myAnimation(0,118,"img/animation/Red/RedNoWand_00000_00",".png",0);
	myAnimation* yellowAnimation = new myAnimation(0,118,"img/animation/Yellow/YellowNoWand_00",".png",0);
	
	myAnimation* animations[3] = {blueAnimation, redAnimation, yellowAnimation};
	myMultiTextureAnimation* drawAnimation = new myMultiTextureAnimation(3,animations);
	drawAnimation->setOrigin(49);
	float drawAnimationRotationStep = 1.0f;
	float rotAngle = 1.0f;

	// Window:
	sf::ContextSettings settings;
	sf::VideoMode videomode = sf::VideoMode(800,600);
	sf::RenderWindow* window = new sf::RenderWindow(videomode, "SFML Game",(sf::Style::Default ^ sf::Style::Resize), settings);
	window->setFramerateLimit(120);
	window->setKeyRepeatEnabled(false);
	window->setMouseCursorVisible(false);

	// Floor:
	GridTileController* gtc = new GridTileController(Globals::PolygonType::PENTAGON);
	GridFloor* gf = new GridFloor(window, 4, 4, gtc);

	// Icon:
	sf::Image smurf;
    smurf.loadFromFile("img/smurf.png");
    window->setIcon(128, 128, smurf.getPixelsPtr());

	// Image:
	sf::Texture tex_smurf;
	tex_smurf.loadFromImage(smurf);
	sf::Sprite sprite(tex_smurf);
	sprite.setOrigin(64,64);
	sprite.setPosition(videomode.width/2-tex_smurf.getSize().x/2, videomode.height/2-tex_smurf.getSize().y/2); 

	// Font:
	sf::Font font;
	if(!font.loadFromFile("Fonts/trebuc.ttf"))
		return 1;
	
	sf::Text myText("Hello, World!", font);
	sf::Text myText2("(Press ESC to close)", font, 10U);
	myText2.setPosition(0, videomode.height-myText2.getCharacterSize()-5);
	
	// Event-variables:	
	sf::Event event;
	bool play = true;
	bool drawText = true;	
	bool lMouse, rMouse, mMouse,lMouseReleased=false,rMouseReleased=false,lMousePrevReleased,rMousePrevReleased;
	lMouse = rMouse = mMouse = false;
	sf::Vector2f mousePos(0,0);

	bool keyEscape = false;
	bool keyT = false;

	// Misc. variables:
	myColorIterator* ci = new myColorIterator();
	float gravity = 9.81f;
	float vx = -3;
	float spriteDx, spriteDy;
	sf::Time elapsed = globals->gameClock->restart();
	int spriteVertDirection = 1;
	int spriteHorDirection = 1;
	int prevSpriteVertDirection = spriteVertDirection;





	// Game loop  //////////////////////
	while(play)
	{
		// EVENTS
		while(window->pollEvent(event))
		{			
			testMouse(sf::Mouse::Button::Left, &lMouse, event);
			testMouse(sf::Mouse::Button::Middle, &mMouse, event);
			testMouse(sf::Mouse::Button::Right, &rMouse, event);
			
			testKey(sf::Keyboard::Escape, &keyEscape, event);
			testKey(sf::Keyboard::T, &keyT, event);
			

			if (event.type == sf::Event::Closed)
			{
				play = false;
			}
			
			if (event.type == sf::Event::MouseButtonReleased)
			{
				lMousePrevReleased = lMouseReleased;
				rMousePrevReleased = rMouseReleased;
				if (event.mouseButton.button == sf::Mouse::Button::Left) 
				{
					lMouseReleased = (!lMousePrevReleased)? true: false;
				}
				if (event.mouseButton.button == sf::Mouse::Button::Right) 
				{
					rMouseReleased = (!rMousePrevReleased)? true: false;
				}
			}
			
			if (event.type == sf::Event::MouseMoved) 
			{
				mousePos.x = event.mouseMove.x;
				mousePos.y = event.mouseMove.y;
			}
			
			if (event.type == sf::Event::MouseLeft)
			{
				drawText = false;
			}
			if (event.type == sf::Event::MouseEntered)
			{
				drawText = true;
			}

		}

		


		// LOGIC
		elapsed = globals->gameClock->getElapsedTime();

		drawAnimation->setTexture((lMouse)? 1: 2);
		drawAnimation->setTexture((rMouse)? 0: drawAnimation->getTextureIndex());
		
		if (keyEscape)
		{
			play = false;
		}

		if (lMouse) 
		{
			myText.setStyle(sf::Text::Style::Underlined);
		}
		else
		{
			myText.setStyle(sf::Text::Style::Regular);
		}

		drawAnimationRotationStep = (rand()%1000<=1)? -drawAnimationRotationStep: drawAnimationRotationStep;
		
		drawAnimation->next();
		drawAnimation->setPosition(mousePos.x, mousePos.y);
		drawAnimation->rotate(drawAnimationRotationStep *( 0.5f*sin((rotAngle+=0.1)/100)));
		ci->iterate();
		myText.setColor(ci->getColor());

		myText.setString(to_string(mousePos.x) + ":" + to_string(mousePos.y));
		if(keyT) myText.setString("Number of tiles: " + to_string(gtc->getNumberOfTiles()));


		// Sprite:
		prevSpriteVertDirection = spriteVertDirection;
		bool spriteIsLeft, spriteIsRight, spriteIsTop, spriteIsBottom;
		spriteIsLeft =		(sprite.getGlobalBounds().left <= 0);
		spriteIsRight =		(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= videomode.width);
		spriteIsTop =		(sprite.getGlobalBounds().top <= 0);
		spriteIsBottom =	(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= videomode.height);

		if (spriteIsLeft || spriteIsRight)
		{
			spriteHorDirection = -spriteHorDirection;			
			globals->getSound(1)->play();
		}

		if (spriteIsTop || spriteIsBottom)
		{
			spriteVertDirection = -spriteVertDirection;
			globals->getSound(0)->play();
		}
		
		double time = (prevSpriteVertDirection == spriteVertDirection)? globals->gameClock->getElapsedTime().asSeconds(): globals->gameClock->restart().asSeconds();

		spriteDx = vx*spriteHorDirection;
		spriteDy = gravity*spriteVertDirection*time;

		sprite.move(spriteDx, spriteDy);

		sprite.setScale(1,(spriteVertDirection>0)? 1: -1);




		// RENDERING
		window->clear();

		



		gf->draw();
		
		window->draw(myText2);

		window->draw(myText);
				
		window->draw(sprite);
		if(drawText) window->draw(*(drawAnimation->getSprite()));



		window->display();

	} // END GAME LOOP //////////////////


	// Clean up
	window->close();


	return 0;
}


// This is a comment without meaning to it :D
