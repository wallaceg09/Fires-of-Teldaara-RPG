#include "Graphics.h"


Graphics::Graphics(int width, int height, int bitsPerPixel, int flags)
{
	SDL_Init( SDL_INIT_EVERYTHING ); 
	scene = SDL_SetVideoMode(width, height, bitsPerPixel, flags);
}


Graphics::~Graphics(void)
{
	SDL_Quit();//TODO: Move this somewhere else
}

SDL_Surface * Graphics::loadImage(std::string filename)
{
	SDL_Surface* loadedImage = NULL;

	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename.c_str());

	if(loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

		SDL_FreeSurface(loadedImage);
	}
	
	return optimizedImage;
}

void Graphics:: applySurface(int x, int y, SDL_Surface* source)
{
	applySurface(x, y, source, NULL);
}

void Graphics::applySurface(int x, int y, SDL_Surface* source, SDL_Rect * subSurface)
{
	SDL_Rect offset;
	offset.y = y;
	offset.x = x;

	SDL_BlitSurface(source, subSurface, this->scene, &offset);
}

bool Graphics::flipScreen()
{
	if(SDL_Flip(this->scene) == 0)
	{
		return true;
	}
	return false;
}
