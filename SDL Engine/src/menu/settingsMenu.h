#pragma once

#include "../engine/gameWindow.h"
#include "../engine/ResourcesManager.h"
#include "../engine/Keyboard.h"
#include "../engine/Mouse.h"
#include "../engine/audio.h"

#include "../stateTransition.h"

#define RENDERER_SETTING 1
#define LIMIT_FPS_SETTING 2
#define DISPLAY_FPS_SETTING 3
#define SCREEN_SETTING 4
#define SCREEN_RESOLUTION 5
#define RETURN_BUTTON 6

class SettingsMenu {

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

	//Button
	SDL_Texture* returnButton;
	SDL_Rect returnButtonRect;

	//Display FPS
	SDL_Texture* fpsDisplayYesSelection;
	SDL_Texture* fpsDisplayNoSelection;

	SDL_Rect fpsDisplayYesSelectionRect;
	SDL_Rect fpsDisplayNoSelectionRect;

	//Screen setting
	SDL_Texture* fullscreenSelection;
	SDL_Texture* windowedSelection;

	SDL_Rect fullscreenSelectionRect;
	SDL_Rect windowedSelectionRect;

	//Render setting
	SDL_Texture* softwareSelection;
	SDL_Texture* hardwareSelection;
	SDL_Texture* vSyncSelection;

	SDL_Rect softwareSelectionRect;
	SDL_Rect hardwareSelectionRect;
	SDL_Rect vSyncSelectionRect;

	//FPS limit setting
	SDL_Texture* fps30Selection;
	SDL_Texture* fps60Selection;
	SDL_Texture* fps120Selection;
	SDL_Texture* fpsUnlimitedSelection;

	SDL_Rect fps30SelectionRect;
	SDL_Rect fps60SelectionRect;
	SDL_Rect fps120SelectionRect;
	SDL_Rect fpsUnlimitedSelectionRect;

	//Resolution setting
	SDL_Texture* resolution480Selection;
	SDL_Texture* resolution600Selection;
	SDL_Texture* resolution720Selection;
	SDL_Texture* resolution900Selection;
	SDL_Texture* resolution1080Selection;
	SDL_Texture* resolution1440Selection;
	SDL_Texture* resolution2160Selection;

	SDL_Rect resolution480SelectionRect;
	SDL_Rect resolution600SelectionRect;
	SDL_Rect resolution720SelectionRect;
	SDL_Rect resolution900SelectionRect;
	SDL_Rect resolution1080SelectionRect;
	SDL_Rect resolution1440SelectionRect;
	SDL_Rect resolution2160SelectionRect;

	//Hover image
	SDL_Texture* buttonHover;
	SDL_Rect buttonHoverRect;

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
	SettingsMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio);
	~SettingsMenu();

	int flow();

};