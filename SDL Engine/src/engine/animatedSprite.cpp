#include "animatedSprite.h"

AnimatedSprite::AnimatedSprite() : Sprite() {

	frameCounter = 0;

	columns = 0;
	maxFrame = 0;
	frameDelay = 0;
	currentFrame = 0;

	reverseAnim = false;

}

AnimatedSprite::~AnimatedSprite() { }bool AnimatedSprite::displayAnimationOnce(GameWindow& wnd) {

	//use to extract and draw an individual frame to the screen

	frameCounter++;

	if (frameCounter > frameDelay) {

		frameCounter = 0;

		if (reverseAnim) { currentFrame--; } //backward to previous frame
		else { currentFrame++; } //forward to next frame

	}

	// prevent animation from continueing after running through full animation once
	if (reverseAnim) {

		if (currentFrame < 0) {
			currentFrame = maxFrame - 1;
			return true;
		}

	}
	else {

		if (currentFrame >= currentFrame) {
			currentFrame = 0;
			return true;
		}

	}

	//use algorithm to extract the image out from sprite image
	extractImageFrame(wnd);

	return false;

}

void AnimatedSprite::displayAnimation(GameWindow& wnd) {

	//use to extract and draw an individual frame to the screen

	frameCounter++;

	if (frameCounter > frameDelay) {

		frameCounter = 0;

		if (reverseAnim) { currentFrame--; } //backward to previous frame
		else { currentFrame++; } //forward to next frame

	}

	//resetting animation to continue loop
	if (reverseAnim) {
		if (currentFrame < 0) { currentFrame = maxFrame - 1; }
	}
	else {
		if (currentFrame > maxFrame - 1) { currentFrame = 0; }
	}

	//use algorithm to extract the image out from sprite image
	extractImageFrame(wnd);

}

void AnimatedSprite::extractImageFrame(GameWindow& wnd) {

	//get total column from the sprite image
	columns = imageWidth / displayRect.w;

	//key part to extract the image from sprite sheet
	animRect.y = (currentFrame / columns) * spriteRect.h;
	animRect.x = (currentFrame % columns) * spriteRect.w;

	animRect.w = spriteRect.w;
	animRect.h = spriteRect.h;

	SDL_RenderCopyEx(wnd.renderer, spriteImage, &animRect, &displayRect, angle, center, flip);

}

void AnimatedSprite::setAnimationProperties(int maxFrame, int frameDelay, bool reverseAnim) {

	this->maxFrame = maxFrame;
	this->frameDelay = frameDelay;

	currentFrame = 0; //the first frame
	frameCounter = 0; //starting counter

	this->reverseAnim = reverseAnim;

}

void AnimatedSprite::setAnimationProperties(int maxFrame, int frameDelay, int currentFrame, int frameCounter, bool reverseAnim) {

	this->maxFrame = maxFrame;
	this->frameDelay = frameDelay;
	this->currentFrame = currentFrame;
	this->frameCounter = frameCounter;
	this->reverseAnim = reverseAnim;

}

void AnimatedSprite::setIsAnimationReverse(bool reverseAnim) {
	this->reverseAnim = reverseAnim;
}

bool AnimatedSprite::getIsAnimationReverse() {
	return reverseAnim;
}

void AnimatedSprite::setAnimationColumns(int columns) {
	this->columns = columns;
}

int AnimatedSprite::getAnimationColumns() {
	return columns;
}

void AnimatedSprite::setAnimationMaxFrames(int maxFrame) {
	this->maxFrame = maxFrame;
}

int AnimatedSprite::getAnimationMaxFrames() {
	return maxFrame;
}

void AnimatedSprite::setAnimationCurrentFrame(int currentFrame) {
	this->currentFrame = currentFrame;
}

int AnimatedSprite::getAnimationCurrentFrame() {
	return currentFrame;
}

void AnimatedSprite::setAnimationFrameDelay(int frameDelay) {
	this->frameDelay = frameDelay;
}

int AnimatedSprite::getAnimationFrameDelay() {
	return frameDelay;
}