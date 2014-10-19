#include "SDL.h"
#include "Graphics.h"
#include "Sprite.h"

#include <string>
#include <ostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BITS_PER_PIXEL = 32;
const int SDL_FLAGS = SDL_SWSURFACE;
const std::string DEBUG_SPRITE_FILENAME = "res/sprites/wizard.png";

using std::cout;

int main( int argc, char* args[] ) { 
	Graphics graphics(SCREEN_WIDTH, SCREEN_HEIGHT, BITS_PER_PIXEL, SDL_FLAGS);
	SDL_Surface *debugSpriteSurface = graphics.loadImage(DEBUG_SPRITE_FILENAME);
	if(debugSpriteSurface != NULL)
	{
		Sprite debugSprite("wizard", 0, 0, 26*3, 26*3, debugSpriteSurface);
		graphics.applySurface(150, 150, debugSpriteSurface, &debugSprite.getRect());
		cout << graphics.flipScreen();
		SDL_Delay(5000);
		return 0; 
	}
	else
	{
		cout << "There was an error opening the file: " << DEBUG_SPRITE_FILENAME;
	}
}