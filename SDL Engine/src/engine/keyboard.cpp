#include "keyboard.h"

Keyboard::Keyboard() {

	// ** Initialise everything here ** //

	kbdInput = (Uint8*)SDL_GetKeyboardState(NULL);

	lastKeyState = 0;
	lastHoldState = 0;

	pressDelay = 10;
	pressDelayCounter = 0;

}

Keyboard::~Keyboard() {

	kbdInput = nullptr;

	std::cout << "Keyboard object cleaned" << std::endl;

}

bool Keyboard::isPressed(int keyCode) {

	// ** Checks if key is being pressed ** //

	if (kbdInput[keyCode] && pressDelayCounter == 0) {
		lastKeyState = keyCode;
		pressDelayCounter++;
		return true;
	}

	return false;

}

bool Keyboard::isHold(int keyCode) {

	// ** Checks if key is being hold ** //

	if (kbdInput[keyCode] && lastHoldState == keyCode && pressDelayCounter == 0) {
		pressDelayCounter++;
		//std::cout << keyCode + "key is being hold" << std::endl;
		return true;
	}

	lastHoldState = keyCode;

	return false;

}

void Keyboard::setDelayPress(int delayPress) {

	this->pressDelay = delayPress;

}

int Keyboard::getPressDelay() {

	return pressDelay;

}

void Keyboard::update() {

	if (pressDelayCounter == pressDelay) { pressDelayCounter = 0; }
	else if (pressDelayCounter != 0) { pressDelayCounter++; }

}