#pragma once

#include <sstream>

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"
#include "../engine/font.h"
#include "../engine/sprite.h"

#include "../stateTransition.h"

#include "../menu/inGameMenu.h"
#include "../menu/fightOverMenu.h"

#include "../fighters/fighterCharacters.h"

//template <typename P1_fighter, typename P2_fighter>
class TestStage {

private:
	GameWindow& wnd;
	ResourcesManager& rseMngr;
	Keyboard& kbd;
	Mouse& mse;
	Audio& audio;

private:
	int returnState;
	int currentState;
	int nextState;

	int timerCountdown;
	int timerCounter;

	int floor;

	Font* timer;
	std::stringstream timerText;
	SDL_Rect timerRect;

	SDL_Texture* background;
	SDL_Rect backgroundRect;

	SDL_Texture* healthBarLeft;
	SDL_Rect healthBarLeftRect;

	SDL_Texture* healthBarRight;
	SDL_Rect healthBarRightRect;

	TestFighter1* player1;
	//P1_fighter player1;
	//P2_fighter player2;

	InGameMenu* inGameMenu;
	FightOverMenu* fightOverMenu;

	Mix_Music* bgm;
	Mix_Chunk* menuSound;

private:
	void reset();
	void clampInWindow();
	void buttonControls();
	void countdownTimerDisplay();
	void display();
	void stateManager();
	void update();

public:
	TestStage(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~TestStage();

	int flow();

};