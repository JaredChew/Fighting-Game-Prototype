#include "font.h"

Font::Font(GameWindow& wnd) : wnd(wnd) {

	if (TTF_Init() == -1) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "SDL Font failed to initialise", NULL);
		std::cerr << "SDL failed to initialise font library" << std::endl;

		wnd.forceQuit();

	}

	font = nullptr;
	renderedText = nullptr;
	text = nullptr;

}

Font::~Font() {

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

	//Window close causes error, VS close does not
	//TTF_CloseFont(font);
	font = nullptr;

	std::cout << "Font object cleaned" << std::endl;

}

void Font::setFont(TTF_Font* font) {
	this->font = font;
}

void Font::setFontProperties(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}

void Font::setFontColour(Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

}

void Font::setFontSizeAndDimension(int x, int y, int w, int h) {

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}
void Font::setFontPosition(int x, int y) {

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte

}
void Font::setFontDimensions(int w, int h) {

	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}

void Font::displayFont(std::string msg) {

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	text = SDL_CreateTextureFromSurface(wnd.renderer, renderedText);

	SDL_RenderCopy(wnd.renderer, text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void Font::displayFont(std::string msg, int x, int y, int w, int h) {

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte

	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

	text = SDL_CreateTextureFromSurface(wnd.renderer, renderedText);

	SDL_RenderCopy(wnd.renderer, text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void Font::displayFont(std::string msg, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	text = SDL_CreateTextureFromSurface(wnd.renderer, renderedText);

	SDL_RenderCopy(wnd.renderer, text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void Font::displayFont(std::string msg, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

	text = SDL_CreateTextureFromSurface(wnd.renderer, renderedText);

	SDL_RenderCopy(wnd.renderer, text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

// ########### ARCHIVE ########### //
/*
void Font::close() {

SDL_FreeSurface(renderedText);
renderedText = NULL;

SDL_DestroyTexture(text);
text = NULL;

// !!! Error (when turned on) when game ends !!! //

//TTF_CloseFont(font);
//font = NULL;

//TTF_Quit();

}
*/