#include "settingsMenu.h"

SettingsMenu::SettingsMenu(GameWindow& wnd, ResourcesManager& rseMngr, Keyboard& kbd, Mouse& mse, Audio& audio) : wnd(wnd), rseMngr(rseMngr), kbd(kbd), mse(mse), audio(audio) {

	buttonSelect = NULL;
	returnState = NULL;

	buttonNavigation = SM_RENDER_SOFTWARE;
	buttonSection = RENDERER_SETTING;
	oldButtonSection = buttonSection;

	buttonSpacing = (int)(0.023 * wnd.getWidth());;

	//Background image
	background = rseMngr.loadTextureImage("asset/graphic/settingsMenu.png");
	SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	//Renderer setting
	softwareSelection = rseMngr.loadTextureImage("asset/graphic/softwareSelection.png");
	SDL_QueryTexture(softwareSelection, NULL, NULL, &softwareSelectionRect.w, &softwareSelectionRect.h);
	softwareSelectionRect.x = (int)(0.17 * wnd.getWidth());
	softwareSelectionRect.y = (int)(0.08 * wnd.getHeight());

	hardwareSelection = rseMngr.loadTextureImage("asset/graphic/hardwareSelection.png");
	SDL_QueryTexture(hardwareSelection, NULL, NULL, &hardwareSelectionRect.w, &hardwareSelectionRect.h);
	hardwareSelectionRect.x = (int)(softwareSelectionRect.x + softwareSelectionRect.w + buttonSpacing);
	hardwareSelectionRect.y = (int)softwareSelectionRect.y;

	vSyncSelection = rseMngr.loadTextureImage("asset/graphic/vSyncSelection.png");
	SDL_QueryTexture(vSyncSelection, NULL, NULL, &vSyncSelectionRect.w, &vSyncSelectionRect.h);
	vSyncSelectionRect.x = (int)(hardwareSelectionRect.x + softwareSelectionRect.w + buttonSpacing);
	vSyncSelectionRect.y = (int)hardwareSelectionRect.y;

	//Limit FPS
	fps30Selection = rseMngr.loadTextureImage("asset/graphic/30Selection.png");
	SDL_QueryTexture(fps30Selection, NULL, NULL, &fps30SelectionRect.w, &fps30SelectionRect.h);
	fps30SelectionRect.x = (int)(0.17 * wnd.getWidth());
	fps30SelectionRect.y = (int)(0.15 * wnd.getHeight());

	fps60Selection = rseMngr.loadTextureImage("asset/graphic/60Selection.png");
	SDL_QueryTexture(fps60Selection, NULL, NULL, &fps60SelectionRect.w, &fps60SelectionRect.h);
	fps60SelectionRect.x = (int)(fps30SelectionRect.x + fps30SelectionRect.w + buttonSpacing);
	fps60SelectionRect.y = (int)fps30SelectionRect.y;

	fps120Selection = rseMngr.loadTextureImage("asset/graphic/120Selection.png");
	SDL_QueryTexture(fps120Selection, NULL, NULL, &fps120SelectionRect.w, &fps120SelectionRect.h);
	fps120SelectionRect.x = (int)(fps60SelectionRect.x + fps60SelectionRect.w + buttonSpacing);
	fps120SelectionRect.y = (int)fps60SelectionRect.y;

	fpsUnlimitedSelection = rseMngr.loadTextureImage("asset/graphic/unlimitedSelection.png");
	SDL_QueryTexture(fpsUnlimitedSelection, NULL, NULL, &fpsUnlimitedSelectionRect.w, &fpsUnlimitedSelectionRect.h);
	fpsUnlimitedSelectionRect.x = (int)(fps120SelectionRect.x + fps120SelectionRect.w + buttonSpacing);
	fpsUnlimitedSelectionRect.y = (int)fps120SelectionRect.y;

	//Display FPS counter
	fpsDisplayYesSelection = rseMngr.loadTextureImage("asset/graphic/yesSelection.png");
	SDL_QueryTexture(fpsDisplayYesSelection, NULL, NULL, &fpsDisplayYesSelectionRect.w, &fpsDisplayYesSelectionRect.h);
	fpsDisplayYesSelectionRect.x = (int) (0.285 * wnd.getWidth());
	fpsDisplayYesSelectionRect.y = (int)(0.225 * wnd.getHeight());

	fpsDisplayNoSelection = rseMngr.loadTextureImage("asset/graphic/noSelection.png");
	SDL_QueryTexture(fpsDisplayNoSelection, NULL, NULL, &fpsDisplayNoSelectionRect.w, &fpsDisplayNoSelectionRect.h);
	fpsDisplayNoSelectionRect.x = (int) (fpsDisplayYesSelectionRect.x + fpsDisplayYesSelectionRect.w + buttonSpacing);
	fpsDisplayNoSelectionRect.y = (int)fpsDisplayYesSelectionRect.y;

	//Screen setting
	fullscreenSelection = rseMngr.loadTextureImage("asset/graphic/fullscreenSelection.png");
	SDL_QueryTexture(fullscreenSelection, NULL, NULL, &fullscreenSelectionRect.w, &fullscreenSelectionRect.h);
	fullscreenSelectionRect.x = (int)(0.24 * wnd.getWidth());
	fullscreenSelectionRect.y = (int)(0.305 * wnd.getHeight());

	windowedSelection = rseMngr.loadTextureImage("asset/graphic/windowedSelection.png");
	SDL_QueryTexture(windowedSelection, NULL, NULL, &windowedSelectionRect.w, &windowedSelectionRect.h);
	windowedSelectionRect.x = (int) ((fullscreenSelectionRect.x + fullscreenSelectionRect.w) + buttonSpacing);
	windowedSelectionRect.y = (int) fullscreenSelectionRect.y;

	//Screen resolution
	resolution480Selection = rseMngr.loadTextureImage("asset/graphic/480pSelection.png");
	SDL_QueryTexture(resolution480Selection, NULL, NULL, &resolution480SelectionRect.w, &resolution480SelectionRect.h);
	resolution480SelectionRect.x = (int) (0.27 * wnd.getWidth());
	resolution480SelectionRect.y = (int) (0.38 * wnd.getHeight());

	resolution600Selection = rseMngr.loadTextureImage("asset/graphic/600pSelection.png");
	SDL_QueryTexture(resolution600Selection, NULL, NULL, &resolution600SelectionRect.w, &resolution600SelectionRect.h);
	resolution600SelectionRect.x = (int) (resolution480SelectionRect.x + resolution480SelectionRect.w + (buttonSpacing * 0.5));
	resolution600SelectionRect.y = (int) resolution480SelectionRect.y;

	resolution720Selection = rseMngr.loadTextureImage("asset/graphic/720pSelection.png");
	SDL_QueryTexture(resolution720Selection, NULL, NULL, &resolution720SelectionRect.w, &resolution720SelectionRect.h);
	resolution720SelectionRect.x = (int) (resolution600SelectionRect.x + resolution600SelectionRect.w + (buttonSpacing * 0.5));
	resolution720SelectionRect.y = (int)resolution600SelectionRect.y;

	resolution900Selection = rseMngr.loadTextureImage("asset/graphic/900pSelection.png");
	SDL_QueryTexture(resolution900Selection, NULL, NULL, &resolution900SelectionRect.w, &resolution900SelectionRect.h);
	resolution900SelectionRect.x = (int) (resolution720SelectionRect.x + resolution720SelectionRect.w + (buttonSpacing * 0.5));
	resolution900SelectionRect.y = (int) resolution720SelectionRect.y;

	resolution1080Selection = rseMngr.loadTextureImage("asset/graphic/1080pSelection.png");
	SDL_QueryTexture(resolution1080Selection, NULL, NULL, &resolution1080SelectionRect.w, &resolution1080SelectionRect.h);
	resolution1080SelectionRect.x = (int) resolution480SelectionRect.x;
	resolution1080SelectionRect.y = (int) (resolution480SelectionRect.y + buttonSpacing + (buttonSpacing * 0.5));

	resolution1440Selection = rseMngr.loadTextureImage("asset/graphic/1440pSelection.png");
	SDL_QueryTexture(resolution1440Selection, NULL, NULL, &resolution1440SelectionRect.w, &resolution1440SelectionRect.h);
	resolution1440SelectionRect.x = (int) (resolution1080SelectionRect.x + resolution1080SelectionRect.w + (buttonSpacing * 0.5));
	resolution1440SelectionRect.y = (int) resolution1080SelectionRect.y;

	resolution2160Selection = rseMngr.loadTextureImage("asset/graphic/2160pSelection.png");
	SDL_QueryTexture(resolution2160Selection, NULL, NULL, &resolution2160SelectionRect.w, &resolution2160SelectionRect.h);
	resolution2160SelectionRect.x = (int) (resolution1440SelectionRect.x + resolution1440SelectionRect.w + (buttonSpacing * 0.5));
	resolution2160SelectionRect.y = (int) resolution1440SelectionRect.y;

	//Buttons
	returnButton = rseMngr.loadTextureImage("asset/graphic/returnButton.png");
	SDL_QueryTexture(returnButton, NULL, NULL, &returnButtonRect.w, &returnButtonRect.h);
	returnButtonRect.x = (int) (0.055 * wnd.getWidth());
	returnButtonRect.y = (int) (resolution2160SelectionRect.y + (buttonSpacing * 5));

	//Hover
	buttonHover = rseMngr.loadTextureImage("asset/graphic/hoverButton.png");
	SDL_QueryTexture(fpsDisplayYesSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
	buttonHoverRect.x = fpsDisplayYesSelectionRect.x;
	buttonHoverRect.y = fpsDisplayYesSelectionRect.y + buttonSpacing;

	//Sounds
	selectSound = rseMngr.loadSound("asset/sound/buttonNavigate.wav");
	navigateSound = rseMngr.loadSound("asset/sound/buttonSelect_test.wav");

}

SettingsMenu::~SettingsMenu() {

	//Background
	SDL_DestroyTexture(background);
	background = nullptr;

	//Button
	SDL_DestroyTexture(returnButton);
	returnButton = nullptr;

	//Display FPS
	SDL_DestroyTexture(fpsDisplayYesSelection);
	fpsDisplayYesSelection = nullptr;

	SDL_DestroyTexture(fpsDisplayNoSelection);
	fpsDisplayNoSelection = nullptr;

	//Screen settings
	SDL_DestroyTexture(fullscreenSelection);
	fullscreenSelection = nullptr;

	SDL_DestroyTexture(windowedSelection);
	windowedSelection = nullptr;

	//Render settings
	SDL_DestroyTexture(softwareSelection);
	softwareSelection = nullptr;

	SDL_DestroyTexture(hardwareSelection);
	hardwareSelection = nullptr;

	SDL_DestroyTexture(vSyncSelection);
	vSyncSelection = nullptr;

	//FPS limit settings
	SDL_DestroyTexture(fps30Selection);
	fps30Selection = nullptr;

	SDL_DestroyTexture(fps60Selection);
	fps60Selection = nullptr;

	SDL_DestroyTexture(fps120Selection);
	fps120Selection = nullptr;

	SDL_DestroyTexture(fpsUnlimitedSelection);
	fpsUnlimitedSelection = nullptr;

	//Resolution settings
	SDL_DestroyTexture(resolution480Selection);
	resolution480Selection = nullptr;

	SDL_DestroyTexture(resolution600Selection);
	resolution600Selection = nullptr;

	SDL_DestroyTexture(resolution720Selection);
	resolution720Selection = nullptr;

	SDL_DestroyTexture(resolution900Selection);
	resolution900Selection = nullptr;

	SDL_DestroyTexture(resolution1080Selection);
	resolution1080Selection = nullptr;

	SDL_DestroyTexture(resolution1440Selection);
	resolution1440Selection = nullptr;

	SDL_DestroyTexture(resolution2160Selection);
	resolution2160Selection = nullptr;

	//Hover image
	SDL_DestroyTexture(buttonHover);
	buttonHover = nullptr;

	//Sounds
	Mix_FreeChunk(selectSound);
	selectSound = nullptr;

	Mix_FreeChunk(navigateSound);
	navigateSound = nullptr;

}

void SettingsMenu::buttonSectionManager() {

	switch (buttonSection) {

		case RENDERER_SETTING:
			buttonNavigation = SM_RENDER_SOFTWARE;
			break;

		case LIMIT_FPS_SETTING:
			buttonNavigation = SM_FPS_LIMIT_30;
			break;

		case DISPLAY_FPS_SETTING:
			buttonNavigation = SM_SHOW_FPS_ON;
			break;

		case SCREEN_SETTING:
			buttonNavigation = SM_SCREEN_FULLSCREEN;
			break;

		case SCREEN_RESOLUTION:
			buttonNavigation = SM_RESOLUTION_480;
			break;

		case RETURN_BUTTON:
			buttonNavigation = SM_RETURN_BUTTON;
			break;

	}

	oldButtonSection = buttonSection;

}

void SettingsMenu::buttonNavigationManager() {

	//Control button navigation within number of buttons
	switch (buttonNavigation) {

		case SM_RENDER_SOFTWARE:
		case SM_RENDER_HARDWARE:
		case SM_RENDER_V_SYNC:
			buttonSection = RENDERER_SETTING;
			break;

		case SM_FPS_LIMIT_30:
		case SM_FPS_LIMIT_60:
		case SM_FPS_LIMIT_120:
		case SM_FPS_LIMIT_UNLIMITED:
			buttonSection = LIMIT_FPS_SETTING;
			break;

		case SM_SHOW_FPS_ON:
		case SM_SHOW_FPS_OFF:
			buttonSection = DISPLAY_FPS_SETTING;
			break;

		case SM_SCREEN_FULLSCREEN:
		case SM_SCREEN_WINDOWED:
			buttonSection = SCREEN_SETTING;
			break;

		case SM_RESOLUTION_480:
		case SM_RESOLUTION_600:
		case SM_RESOLUTION_720:
		case SM_RESOLUTION_900:
		case SM_RESOLUTION_1080:
		case SM_RESOLUTION_1440:
		case SM_RESOLUTION_2160:
			buttonSection = SCREEN_RESOLUTION;
			break;

		case SM_RETURN_BUTTON:
			buttonSection = RETURN_BUTTON;
			break;

	}

	oldButtonSection = buttonSection;

}

void SettingsMenu::buttonSelectManager() {

	switch (buttonSelect) {

	case SM_SCREEN_FULLSCREEN:
		wnd.setFullScreen(true);
		break;

	case SM_SCREEN_WINDOWED:
		wnd.setFullScreen(false);
		break;

	case SM_RENDER_SOFTWARE:
		wnd.setRenderType(0);
		break;

	case SM_RENDER_HARDWARE:
		wnd.setRenderType(1);
		break;

	case SM_RENDER_V_SYNC:
		wnd.setRenderType(2);
		break;

	case SM_FPS_LIMIT_UNLIMITED:
		wnd.setMaxFPS(0);
		kbd.setDelayPress(240);
		break;

	case SM_FPS_LIMIT_120:
		wnd.setMaxFPS(120);
		kbd.setDelayPress((int)(0.17 * 120));
		break;

	case SM_FPS_LIMIT_60:
		wnd.setMaxFPS(60);
		kbd.setDelayPress((int)(0.17 * 60));
		break;

	case SM_FPS_LIMIT_30:
		wnd.setMaxFPS(30);
		kbd.setDelayPress((int)(0.17 * 30));
		break;

	case SM_SHOW_FPS_ON:
		wnd.setDisplayFPS(true);
		break;

	case SM_SHOW_FPS_OFF:
		wnd.setDisplayFPS(false);
		break;

	case SM_RESOLUTION_480:
		wnd.setResolution(640, 480);
		break;

	case SM_RESOLUTION_600:
		wnd.setResolution(800, 600);
		break;

	case SM_RESOLUTION_720:
		wnd.setResolution(1280, 720);
		break;

	case SM_RESOLUTION_900:
		wnd.setResolution(1600, 900);
		break;

	case SM_RESOLUTION_1080:
		wnd.setResolution(1920, 1080);
		break;

	case SM_RESOLUTION_1440:
		wnd.setResolution(2560, 1440);
		break;

	case SM_RESOLUTION_2160:
		wnd.setResolution(3840, 2160);
		break;

	case SM_RETURN_BUTTON:
		returnState = MM_MAIN_MENU;
		break;

	}

	buttonSelect = NULL;

}

void SettingsMenu::buttonHoverManager() {

	//Button section controller
	if (buttonSection != oldButtonSection) {
		buttonSectionManager();
	}
	else {
		buttonNavigationManager();
	}

	//Change hover button to appropriate button
	switch (buttonNavigation) {

	case SM_SHOW_FPS_ON:
		SDL_QueryTexture(fpsDisplayYesSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fpsDisplayYesSelectionRect.x;
		buttonHoverRect.y = fpsDisplayYesSelectionRect.y;
		//buttonHoverRect.w = fpsDisplayYesSelectionRect.w;
		//buttonHoverRect.h = fpsDisplayYesSelectionRect.h;
		break;

	case SM_SHOW_FPS_OFF:
		SDL_QueryTexture(fpsDisplayNoSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fpsDisplayNoSelectionRect.x;
		buttonHoverRect.y = fpsDisplayNoSelectionRect.y;
		//buttonHoverRect.w = fpsDisplayNoSelectionRect.w;
		//buttonHoverRect.h = fpsDisplayNoSelectionRect.h;
		break;

	case SM_SCREEN_FULLSCREEN:
		SDL_QueryTexture(fullscreenSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fullscreenSelectionRect.x;
		buttonHoverRect.y = fullscreenSelectionRect.y;
		//buttonHoverRect.w = fullscreenSelectionRect.w;
		//buttonHoverRect.h = fullscreenSelectionRect.h;
		break;

	case SM_SCREEN_WINDOWED:
		SDL_QueryTexture(windowedSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = windowedSelectionRect.x;
		buttonHoverRect.y = windowedSelectionRect.y;
		//buttonHoverRect.w = windowedSelectionRect.w;
		//buttonHoverRect.h = windowedSelectionRect.h;
		break;

	case SM_RENDER_SOFTWARE:
		SDL_QueryTexture(softwareSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = softwareSelectionRect.x;
		buttonHoverRect.y = softwareSelectionRect.y;
		//buttonHoverRect.w = softwareSelectionRect.w;
		//buttonHoverRect.h = softwareSelectionRect.h;
		break;

	case SM_RENDER_HARDWARE:
		SDL_QueryTexture(hardwareSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = hardwareSelectionRect.x;
		buttonHoverRect.y = hardwareSelectionRect.y;
		//buttonHoverRect.w = hardwareSelectionRect.w;
		//buttonHoverRect.h = hardwareSelectionRect.h;
		break;

	case SM_RENDER_V_SYNC:
		SDL_QueryTexture(vSyncSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = vSyncSelectionRect.x;
		buttonHoverRect.y = vSyncSelectionRect.y;
		//buttonHoverRect.w = vSyncSelectionRect.w;
		//buttonHoverRect.h = vSyncSelectionRect.h;
		break;

	case SM_FPS_LIMIT_30:
		SDL_QueryTexture(fps30Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fps30SelectionRect.x;
		buttonHoverRect.y = fps30SelectionRect.y;
		//buttonHoverRect.w = fps30SelectionRect.w;
		//buttonHoverRect.h = fps30SelectionRect.h;
		break;

	case SM_FPS_LIMIT_60:
		SDL_QueryTexture(fps60Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fps60SelectionRect.x;
		buttonHoverRect.y = fps60SelectionRect.y;
		//buttonHoverRect.w = fps60SelectionRect.w;
		//buttonHoverRect.h = fps60SelectionRect.h;
		break;

	case SM_FPS_LIMIT_120:
		SDL_QueryTexture(fps120Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fps120SelectionRect.x;
		buttonHoverRect.y = fps120SelectionRect.y;
		//buttonHoverRect.w = fps120SelectionRect.w;
		//buttonHoverRect.h = fps120SelectionRect.h;
		break;

	case SM_FPS_LIMIT_UNLIMITED:
		SDL_QueryTexture(fpsUnlimitedSelection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = fpsUnlimitedSelectionRect.x;
		buttonHoverRect.y = fpsUnlimitedSelectionRect.y;
		//buttonHoverRect.w = fpsUnlimitedSelectionRect.w;
		//buttonHoverRect.h = fpsUnlimitedSelectionRect.h;
		break;

	case SM_RESOLUTION_480:
		SDL_QueryTexture(resolution480Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution480SelectionRect.x;
		buttonHoverRect.y = resolution480SelectionRect.y;
		//buttonHoverRect.w = resolution480SelectionRect.w;
		//buttonHoverRect.h = resolution480SelectionRect.h;
		break;

	case SM_RESOLUTION_600:
		SDL_QueryTexture(resolution600Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution600SelectionRect.x;
		buttonHoverRect.y = resolution600SelectionRect.y;
		//buttonHoverRect.w = resolution600SelectionRect.w;
		//buttonHoverRect.h = resolution600SelectionRect.h;
		break;

	case SM_RESOLUTION_720:
		SDL_QueryTexture(resolution720Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution720SelectionRect.x;
		buttonHoverRect.y = resolution720SelectionRect.y;
		//buttonHoverRect.w = resolution720SelectionRect.w;
		//buttonHoverRect.h = resolution720SelectionRect.h;
		break;

	case SM_RESOLUTION_900:
		SDL_QueryTexture(resolution900Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution900SelectionRect.x;
		buttonHoverRect.y = resolution900SelectionRect.y;
		//buttonHoverRect.w = resolution900SelectionRect.w;
		//buttonHoverRect.h = resolution900SelectionRect.h;
		break;

	case SM_RESOLUTION_1080:
		SDL_QueryTexture(resolution1080Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution1080SelectionRect.x;
		buttonHoverRect.y = resolution1080SelectionRect.y;
		//buttonHoverRect.w = resolution1080SelectionRect.w;
		//buttonHoverRect.h = resolution1080SelectionRect.h;
		break;

	case SM_RESOLUTION_1440:
		SDL_QueryTexture(resolution1440Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution1440SelectionRect.x;
		buttonHoverRect.y = resolution1440SelectionRect.y;
		//buttonHoverRect.w = resolution1440SelectionRect.w;
		//buttonHoverRect.h = resolution1440SelectionRect.h;
		break;

	case SM_RESOLUTION_2160:
		SDL_QueryTexture(resolution2160Selection, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = resolution2160SelectionRect.x;
		buttonHoverRect.y = resolution2160SelectionRect.y;
		//buttonHoverRect.w = resolution2160SelectionRect.w;
		//buttonHoverRect.h = resolution2160SelectionRect.h;
		break;

	case SM_RETURN_BUTTON:
		SDL_QueryTexture(returnButton, NULL, NULL, &buttonHoverRect.w, &buttonHoverRect.h);
		buttonHoverRect.x = returnButtonRect.x;
		buttonHoverRect.y = returnButtonRect.y;
		//buttonHoverRect.w = returnButtonRect.w;
		//buttonHoverRect.h = returnButtonRect.h;
		break;

	}

}

void SettingsMenu::buttonControl() {

	if (kbd.isPressed(SDL_SCANCODE_RETURN)) {
		audio.sound.playSound(selectSound, 0);
		buttonSelect = buttonNavigation;
	}
	else if (kbd.isPressed(SDL_SCANCODE_A) || kbd.isPressed(SDL_SCANCODE_LEFT)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_D) || kbd.isPressed(SDL_SCANCODE_RIGHT)) {
		audio.sound.playSound(navigateSound, 0);
		buttonNavigation++;
	}
	else if (kbd.isPressed(SDL_SCANCODE_W) || kbd.isPressed(SDL_SCANCODE_UP)) {
		audio.sound.playSound(navigateSound, 0);
		buttonSection--;
	}
	else if (kbd.isPressed(SDL_SCANCODE_S) || kbd.isPressed(SDL_SCANCODE_DOWN)) {
		audio.sound.playSound(navigateSound, 0);
		buttonSection++;
	}
	else if (kbd.isPressed(SDL_SCANCODE_BACKSPACE) || kbd.isPressed(SDL_SCANCODE_ESCAPE)) {
		audio.sound.playSound(selectSound, 0);
		returnState = MM_MAIN_MENU;
	}

	//Up-down controls
	if (buttonSection < RENDERER_SETTING) {
		buttonSection = RETURN_BUTTON;
	}
	else if (buttonSection > RETURN_BUTTON) {
		buttonSection = RENDERER_SETTING;
	}

	//Left-right controls
	if (buttonNavigation > SM_RETURN_BUTTON) {
		buttonNavigation = SM_RENDER_SOFTWARE;
	}
	else if (buttonNavigation < SM_RENDER_SOFTWARE) {
		buttonNavigation = SM_RETURN_BUTTON;
	}

	buttonHoverManager();

}

void SettingsMenu::display() {

	//Background
	SDL_RenderCopy(wnd.renderer, background, NULL, &backgroundRect);

	//Button hover
	SDL_RenderCopy(wnd.renderer, buttonHover, NULL, &buttonHoverRect);

	//FPS display setting
	SDL_RenderCopy(wnd.renderer, fpsDisplayYesSelection, NULL, &fpsDisplayYesSelectionRect);
	SDL_RenderCopy(wnd.renderer, fpsDisplayNoSelection, NULL, &fpsDisplayNoSelectionRect);

	//Screen setting
	SDL_RenderCopy(wnd.renderer, softwareSelection, NULL, &softwareSelectionRect);
	SDL_RenderCopy(wnd.renderer, hardwareSelection, NULL, &hardwareSelectionRect);

	//Render setting
	SDL_RenderCopy(wnd.renderer, fullscreenSelection, NULL, &fullscreenSelectionRect);
	SDL_RenderCopy(wnd.renderer, windowedSelection, NULL, &windowedSelectionRect);

	//FPS limit setting
	SDL_RenderCopy(wnd.renderer, vSyncSelection, NULL, &vSyncSelectionRect);
	SDL_RenderCopy(wnd.renderer, fps30Selection, NULL, &fps30SelectionRect);
	SDL_RenderCopy(wnd.renderer, fps60Selection, NULL, &fps60SelectionRect);
	SDL_RenderCopy(wnd.renderer, fps120Selection, NULL, &fps120SelectionRect);
	SDL_RenderCopy(wnd.renderer, fpsUnlimitedSelection, NULL, &fpsUnlimitedSelectionRect);

	//Resolution setting
	SDL_RenderCopy(wnd.renderer, resolution480Selection, NULL, &resolution480SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution600Selection, NULL, &resolution600SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution720Selection, NULL, &resolution720SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution900Selection, NULL, &resolution900SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution1080Selection, NULL, &resolution1080SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution1440Selection, NULL, &resolution1440SelectionRect);
	SDL_RenderCopy(wnd.renderer, resolution2160Selection, NULL, &resolution2160SelectionRect);

	//Return button
	SDL_RenderCopy(wnd.renderer, returnButton, NULL, &returnButtonRect);

}

int SettingsMenu::flow() {

	display();

	buttonControl();

	if (buttonSelect != NULL) {
		buttonSelectManager();
	}

	return returnState;

}