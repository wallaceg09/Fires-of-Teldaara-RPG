#pragma once

#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Graphics
{
public:
	Graphics(int width, int height, int bitsPerPixel, int tmp);
	~Graphics(void);

	SDL_Surface *loadImage(std::string filename);
	void applySurface(int x, int y, SDL_Surface* source);
	void applySurface(int x, int y, SDL_Surface* source, SDL_Rect * subSurface);
	bool flipScreen();

private:
	SDL_Surface *scene;
};

