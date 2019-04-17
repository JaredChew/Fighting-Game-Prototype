#pragma once

#include <SDL.h>

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"

#include "settingsMenu.h"
#include "loadMenu.h"

#include "../stateTransition.h"

class MainMenu {

private:
	GameWindow& wnd;
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

	//Objects
	SettingsMenu* settingsMenu;
	LoadMenu* loadMenu;

	//Background
	SDL_Texture* background;
	SDL_Rect backgroundRect;

	//Buttons
	SDL_Texture* continueGameButton;
	SDL_Texture* newGameButton;
	SDL_Texture* loadGameButton;
	SDL_Texture* settingsMenuButton;
	SDL_Texture* quitGameButton;

	SDL_Rect continueGameButtonRect;
	SDL_Rect newGameButtonRect;
	SDL_Rect loadGameButtonRect;
	SDL_Rect settingsMenuButtonRect;
	SDL_Rect quitGameButtonRect;

	//Hover
	SDL_Texture* buttonHover;
	SDL_Rect hoverRect;

	//Sound
	Mix_Chunk* selectSound;
	Mix_Chunk* navigateSound;

private:
	void initialiser();
	void destroyer();

	void buttonSelectManager();
	void buttonControl();

	void display();

public:
	MainMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~MainMenu();

	int flow();

};