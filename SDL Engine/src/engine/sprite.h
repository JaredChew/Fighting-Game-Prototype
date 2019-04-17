#pragma once

#include <iostream>
#include <SDL.h>

#include "gameWindow.h"

class Sprite {

protected:

	SDL_Texture* spriteImage;

	int imageWidth;
	int imageHeight;

	SDL_Rect spriteRect;
	SDL_Rect displayRect;

	double angle;
	SDL_Point* center;

	SDL_RendererFlip flip;

public:

	Sprite();
	~Sprite();

	void display(GameWindow& wnd);
	void clean();

	//Sprite position on screen

	void setPosX(int x);
	void setPosY(int y);

	int getPosX();
	int getPosY();

	//Which part of the Sprite's image will display from top left XY to bottom right XY

	void setImageStartPosition(int x, int y);
	
	void setImageStartX(int x);
	void setImageStartY(int y);

	int getImageStartX();
	int getImageStartY();

	//size of display frame of sprite

	void setDisplayFrameDimension(int x, int h);

	void setDisplayFrameW(int w);
	void setDisplayFrameH(int h);

	int getDisplayFrameW();
	int getDisplayFrameH();

	//size of sprite image

	void setImageDimension(int w, int h);

	void setImageSizeW(int w);
	void setImageSizeH(int h);

	int getImageSizeW();
	int getImageSizeH();

	//SDL_Rect of sprite and display frame

	SDL_Rect getImageRect();
	SDL_Rect getDisplayFrameRect();

	void setDisplayRect(int x, int y, int w, int h);
	void setImageRect(int x, int y, int w, int h);

	//sprite rotation value
	void setRotationAngle(double angle);
	double getRotationAngle();

	//sprite center point for rotation and movement (???)
	void setSpriteCenter(SDL_Point* center);
	SDL_Point* getSpriteCenter();

	//sprite image flip
	SDL_RendererFlip getFlip();
	void setFlip(SDL_RendererFlip flip);

	//sprite image
	SDL_Texture* getImage();
	void setImage(SDL_Texture* spriteImage);

};