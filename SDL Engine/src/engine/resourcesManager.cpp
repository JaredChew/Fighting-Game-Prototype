#include "ResourcesManager.h"

ResourcesManager::ResourcesManager(GameWindow& wnd) : wnd(wnd) {  }

ResourcesManager::~ResourcesManager() {

	IMG_Quit();
	TTF_Quit();

	std::cout << "ResourceLoader libraries closed" << std::endl;

}

SDL_Surface* ResourcesManager::loadSurfaceImage(const char* imageFileDir) {

	//** Load image and apply alpha masking **//

	SDL_Surface* temp_Image = IMG_Load(imageFileDir);

	std::string fileExtension = imageFileDir;

	if (temp_Image == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Failed to load image", NULL);
		std::cerr << "\nSDL failed to load image at: " << imageFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	if (fileExtension.substr(fileExtension.length() - 3) != "png") { // == "bmp"

		//create optimised image using current image
		temp_Image = SDL_ConvertSurface(temp_Image, wnd.backbuffer->format, 0);

		//Set transparency

		Uint32 colourKey = SDL_MapRGB(temp_Image->format, 255, 0, 255);

		//update system with transparency colour
		SDL_SetColorKey(temp_Image, SDL_TRUE, colourKey);

	}

	return temp_Image;

}

SDL_Texture* ResourcesManager::loadTextureImage(const char* imageFileDir) {

	//** Load image and apply alpha masking **//

	SDL_Surface* temp_Surface = IMG_Load(imageFileDir);

	std::string fileExtension = imageFileDir;

	if (temp_Surface == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Failed to load image", NULL);
		std::cerr << "\nSDL failed to load image at: " << imageFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	if (fileExtension.substr(fileExtension.length() - 3) != "png") { // == "bmp"

		//create optimised image using current image
		temp_Surface = SDL_ConvertSurface(temp_Surface, wnd.backbuffer->format, 0);

		//Set transparency

		Uint32 colourKey = SDL_MapRGB(temp_Surface->format, 255, 0, 255);

		//update system with transparency colour
		SDL_SetColorKey(temp_Surface, SDL_TRUE, colourKey);

		fileExtension = "";

	}

	SDL_Texture *textureToPass = SDL_CreateTextureFromSurface(wnd.renderer, temp_Surface);

	SDL_FreeSurface(temp_Surface);

	return textureToPass;

}

Mix_Chunk* ResourcesManager::loadSound(char* soundFileDir) {

	Mix_Chunk* soundToPass = Mix_LoadWAV(soundFileDir);

	if (soundToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Fail to load Sound Files!", NULL);
		std::cerr << "\nSDL failed to load sound at: " << soundFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return soundToPass;

}

Mix_Music* ResourcesManager::loadMusic(char* MusicFileDir) {

	Mix_Music* musicToPass = Mix_LoadMUS(MusicFileDir);

	if (musicToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Fail to load music Files!", NULL);
		std::cerr << "\nSDL failed to load music at: " << MusicFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return musicToPass;

}

TTF_Font* ResourcesManager::loadFont(char* fontFileDir, int fontSize) {

	TTF_Font* fontToPass = TTF_OpenFont(fontFileDir, fontSize);

	if (fontToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "SDL Font failed to load font", NULL);
		std::cerr << "\nSDL failed to load font at: " << fontFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return fontToPass;

}

// ########### ARCHIVE ########### //
/*
ResourceLoader::ResourceLoader(GameWindow& wnd) : wnd(wnd) {

	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "SDL failed to initialise Image extension library", NULL);
		std::cerr << "SDL failed to load Image Extension PNG library" << std::endl;
	}

}

void ResourceLoader::clean() {

	SDL_FreeSurface(temp_Image);
	IMG_Quit();

	Mix_FreeChunk(soundTemp);
	soundTemp = NULL;

	Mix_FreeMusic(musicTemp);
	musicTemp = NULL;

	TTF_CloseFont(temp_font);
	temp_font = NULL;

	TTF_Quit();

}

// !!! Insede Header File !!! //

	private:

	// Will this method below prevent memory leak ??? //
	//SDL_Surface* temp_Image;
	//Uint32 colourKey;

	//Mix_Chunk* soundTemp;
	//Mix_Music* musicTemp;

	//TTF_Font* temp_font;

	//std::string fileExtension;

*/