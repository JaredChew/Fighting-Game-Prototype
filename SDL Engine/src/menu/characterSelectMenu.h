#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"

#include "../stateTransition.h"

#define MAX_FIGHTERS 20
#define MAX_PLAYERS 2

#define PLAYER_1 1
#define PLAYER_2 2

class CharacterSelect {

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

	int characterFrameSpacing;
	int characterDisplaySpacing;

	int playerSelect;
	int selectedCharacter[MAX_PLAYERS];

	//Background image
	SDL_Texture* background;
	SDL_Rect backgroundRect;

	//Character display
	SDL_Texture* characterDisplayLeft;
	SDL_Rect characterDisplayLeftRect;

	SDL_Texture* characterDisplayRight;
	SDL_Rect characterDisplayRightRect;

	//Pre loaded characters start from 1
	//0 is used for empty character display
	SDL_Texture* characterDisplayPreLoad[MAX_FIGHTERS + 1];

	//Save slot image
	SDL_Texture* characterFrames[MAX_FIGHTERS];
	SDL_Rect characterFramesRect[MAX_FIGHTERS];

	//Hover image
	SDL_Texture* characterFrameHover;
	SDL_Rect characterFrameHoverRect;

	//Sounds
	Mix_Chunk* selectSound;
	Mix_Chunk* navigateSound;

private:
	void buttonSelectManager();
	void buttonHoverManager();
	void buttonControl();

	void display();

public:
	CharacterSelect(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~CharacterSelect();

	int flow();

};