#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"

#include "settingsMenu.h"
#include "loadMenu.h"
//#include "saveMenu.h"

#include "../stateTransition.h"

class InGameMenu {

private:
	GameWindow & wnd;
	ResourcesManager& rseMngr;
	Keyboard& kbd;
	Mouse& mse;
	Audio& audio;

private:
	int currentState;
	int returnState;
	int nextState;

	int navigation;
	int buttonNavigation;
	int buttonSpacing;

	//SaveMenu* saveMenu;
	LoadMenu* loadMenu;
	SettingsMenu* settingsMenu;

	//Background
	SDL_Texture* background;
	SDL_Rect backgroundRect;

	//Buttons
	SDL_Texture* resumeButton;
	SDL_Rect resumeButtonRect;

	SDL_Texture* saveButton;
	SDL_Rect saveButtonButton;

	SDL_Texture* loadButton;
	SDL_Rect loadButtonRect;

	SDL_Texture* settingsButton;
	SDL_Rect settingsButtonRect;

	SDL_Texture* mainMenuButton;
	SDL_Rect mainMenuButtonRect;

	SDL_Texture* quitButton;
	SDL_Rect quitButtonRect;

	//Hover
	SDL_Texture* buttonHover;
	SDL_Rect buttonHoverRect;

	//Sounds
	Mix_Chunk* selectSound;
	Mix_Chunk* navigateSound;

private:
	void initialiser();
	void destroyer();

	void buttonHoverManager();
	void buttonControls();

	void display();

public:
	InGameMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~InGameMenu();

	int flow();

};