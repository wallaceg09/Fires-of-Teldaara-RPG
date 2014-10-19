#pragma once
#include <string>
#include<boost\scoped_array.hpp>
#include<SDL.h>
#include <map>

using std::string;
using std::map;
using boost::scoped_array;

struct Animation;
class Sprite
{
public:
	Sprite(string spriteName, int positionX, int positionY, int width, int height, SDL_Surface *surface);
	~Sprite(void);
	SDL_Rect getRect() {return rectangle;}
	bool addAnimation(string name, Animation animation, bool overwrite);
protected:
	//Rectangle that holds the position and the size of the sprite
	SDL_Rect rectangle;
	//Name of the sprite
	string spriteName;
	//Pointer to the image that holds this sprite
	SDL_Surface *surface;

	map<string, Animation> animations;
};

struct Animation
{
	//Beginning row of the animation
	int row;
	//Beginning column of the animation
	int column;
	//Number of columns in the animation
	int length;
	
	//Current frame
	int currentFrame;
	//Time per frame
	int frameTime;
	//Time since last frame-change
	int elapsedTime;
};