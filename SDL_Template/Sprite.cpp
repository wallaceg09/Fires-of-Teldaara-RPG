#include "Sprite.h"


Sprite::Sprite(string spriteName, int positionX, int positionY, int width, int height, SDL_Surface *surface) :
	animations(),
	spriteName(spriteName),
	surface(surface)
{
	this->rectangle.x = positionX;
	this->rectangle.y = positionY;
	this->rectangle.w = width;
	this->rectangle.h = height;
}


Sprite::~Sprite(void)
{
	
}

/*
Checks whether or not the animation already exists, if it does and the user specifies that the animation can be overwritten then it replaces the animation in the animation map.
If it does not exist then the animation is inserted into the animation map.

Inputs
	name		: Name used to identify the animation. Example: "walk_left".
	animation	: The struct containing the animation information.
	overwrite	: Boolean value determining whether or not any animations that are currently in the map. (Default: false)
Output
	true	- if the animation was successfully added.
	false	- if the animation already exists and overwrite is false.
*/
bool Sprite::addAnimation(string name, Animation animation, bool overwrite = false)
{
	if(!overwrite)
	{
		if(animations.find(name) == animations.end())
		{
			return false;
		}
	}

	animations.insert(std::pair<string, Animation>(name, animation));
	return true;
}