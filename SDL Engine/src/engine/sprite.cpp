#include "sprite.h"

Sprite::Sprite() { 

	flip = SDL_FLIP_NONE;

	imageWidth = 0;
	imageHeight = 0;

}

Sprite::~Sprite() {

	SDL_DestroyTexture(spriteImage);
	spriteImage = nullptr;

	center = nullptr;

}

void Sprite::display(GameWindow& wnd) {

	SDL_RenderCopyEx(wnd.renderer, spriteImage, &spriteRect, &displayRect, angle, center, flip);

}

void Sprite::clean() {

	SDL_DestroyTexture(spriteImage);

}

void Sprite::setPosX(int x) {
	displayRect.x = x;
}

void Sprite::setPosY(int y) {
	displayRect.y = y;
}

int Sprite::getPosX() {
	return displayRect.x;
}

int Sprite::getPosY() {
	return displayRect.y;
}

void Sprite::setImageStartPosition(int x, int y) {

	spriteRect.x = x;
	spriteRect.y = y;

}

void Sprite::setImageStartX(int x) {
	spriteRect.x = x;
}

void Sprite::setImageStartY(int y) {
	spriteRect.y = y;
}

int Sprite::getImageStartX() {
	return spriteRect.x;
}

int Sprite::getImageStartY() {
	return spriteRect.y;
}

void Sprite::setDisplayFrameDimension(int w, int h) {

	displayRect.w = w;
	displayRect.h = h;

}

void Sprite::setDisplayFrameW(int w) {
	displayRect.w = w;
}

void Sprite::setDisplayFrameH(int h) {
	displayRect.h = h;
}

int Sprite::getDisplayFrameW() {
	return displayRect.w;
}

int Sprite::getDisplayFrameH() {
	return displayRect.h;
}

void Sprite::setImageDimension(int w, int h) {

	spriteRect.w = w;
	spriteRect.h = h;

}

void Sprite::setImageSizeW(int w) {
	spriteRect.w = w;
}

void Sprite::setImageSizeH(int h) {
	spriteRect.h = h;
}

int Sprite::getImageSizeW() {
	return spriteRect.w;
}

int Sprite::getImageSizeH() {
	return spriteRect.h;
}

void Sprite::setDisplayRect(int x, int y, int w, int h) {

	displayRect.x = x;
	displayRect.y = y;
	displayRect.w = w;
	displayRect.h = h;

}

SDL_Rect Sprite::getDisplayFrameRect() {
	return displayRect;
}

void Sprite::setImageRect(int x, int y, int w, int h) {

	spriteRect.x = x;
	spriteRect.y = y;
	spriteRect.w = w;
	spriteRect.h = h;

}

SDL_Rect Sprite::getImageRect() {
	return spriteRect;
}

void Sprite::setRotationAngle(double angle) {
	this->angle = angle;
}

double Sprite::getRotationAngle() {
	return angle;
}

void Sprite::setSpriteCenter(SDL_Point* center) {
	this->center = center;
}

SDL_Point* Sprite::getSpriteCenter() {
	return center;
}

void Sprite::setFlip(SDL_RendererFlip flip) {
	this->flip = flip;
}

SDL_RendererFlip Sprite::getFlip() {
	return flip;
}

void Sprite::setImage(SDL_Texture* spriteImage) {

	this->spriteImage = spriteImage;

	SDL_QueryTexture(spriteImage, NULL, NULL, &imageWidth, &imageHeight);

}

SDL_Texture* Sprite::getImage() { return spriteImage; }