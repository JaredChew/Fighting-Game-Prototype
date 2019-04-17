#pragma once

#include <SDL.h>
#include <iostream>

#include "keyboardCode.h"

class Keyboard {

private:
	Uint8* kbdInput;

	int lastKeyState;
	int lastHoldState;

	int pressDelay;
	int pressDelayCounter;

public:
	Keyboard();
	~Keyboard();

	void setDelayPress(int delayPress);

	bool isPressed(int keyCode);
	bool isHold(int KeyCode);

	int getPressDelay();

	int getLastKeyState();
	int getLastHoldState();

	void update();

};