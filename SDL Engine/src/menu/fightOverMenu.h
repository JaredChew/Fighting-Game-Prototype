#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"
#include "../engine/font.h"

#include "../stateTransition.h"

class FightOverMenu {

private:
	GameWindow & wnd;
	ResourcesManager& rseMngr;
	Keyboard& kbd;
	Mouse& mse;
	Audio& audio;

private:
	int returnState;
	int nextState;

	int buttonSpacing;

	int buttonNavigation;

	//Background
	SDL_Texture* background;
	SDL_Rect backgroundRect;

	//Winner
	SDL_Texture* winner; //not set
	SDL_Rect winnerRect;

	//Buttons
	SDL_Texture* rematchButton;
	SDL_Rect rematchButtonRect;

	SDL_Texture* changeCharacterButton;
	SDL_Rect changeCharacterButtonRect;

	SDL_Texture* mainMenuButton;
	SDL_Rect mainMenuButtonRect;

	//Hover
	SDL_Texture* buttonHover;
	SDL_Rect buttonHoverRect;

	//Sounds
	Mix_Chunk* selectSound;
	Mix_Chunk* navigateSound;
	

private:
	void buttonSelectManager();
	void buttonHoverManager();
	void buttonControls();

	void display();

public:
	FightOverMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~FightOverMenu();

	int flow();

};