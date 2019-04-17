#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"

#include "../stateTransition.h"

#define SAVE_SLOTS 1
#define BUTTONS 2

#define MAX_SAVE_SLOTS 8

class LoadMenu {

private:
	GameWindow & wnd;
	ResourcesManager& rseMngr;
	Keyboard& kbd;
	Mouse& mse;
	Audio& audio;

private:
	int returnState;

	int buttonSelect;
	int buttonNavigation;
	int buttonSection;
	int oldButtonSection;

	int buttonSpacing;

	//Background image
	SDL_Texture* background;
	SDL_Rect backgroundRect;

	//Save slot image
	SDL_Texture* saveSlot[MAX_SAVE_SLOTS];
	SDL_Rect saveSlotRect[MAX_SAVE_SLOTS];

	//Button
	SDL_Texture* prevPageButton;
	SDL_Rect prevPageButtonRect;

	SDL_Texture* returnButton;
	SDL_Rect returnButtonRect;

	SDL_Texture* nextPageButton;
	SDL_Rect nextPageButtonRect;

	//Hover image
	SDL_Texture* buttonHover;
	SDL_Rect buttonHoverRect;

	SDL_Texture* saveSlotHover;
	SDL_Rect saveSlotHoverRect;

	//Sounds
	Mix_Chunk* selectSound;
	Mix_Chunk* navigateSound;

private:
	void buttonSectionManager();
	void buttonNavigationManager();
	void buttonSelectManager();
	void buttonHoverManager();
	void buttonControl();

	void display();

public:
	LoadMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~LoadMenu();

	int flow();

};