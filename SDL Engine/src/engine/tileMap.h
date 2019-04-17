#pragma once

#include <vector>

#include "gameWindow.h"
#include "animatedSprite.h"

template<int mapSize> class TileMap {

	private:
		GameWindow& wnd;

	private:
		std::vector<AnimatedSprite> tile;
		std::vector<AnimatedSprite> background;

		int tileSize;

		int totalTileX;
		int totalTileY;

		int layer1[mapSize];
		int layer2[mapSize];
		int layer3[mapSize];

		bool obstacle[mapSize];

	public:

		TileMap(GameWindow& wnd);
		~TileMap();

		void scrollMap();

		void setTile(SDL_Texture* tileImage);
		void setTileSize(int tileSize);
		void setTileDimensions(int totalTileX, int totalTileY);
		void setTileAnimationProperties(int tile, int maxFrame, int frameDelay, int currentFrame, int frameCounter, bool reverseAnim);

		void layer1Mapping(int layer1[]);
		void layer2Mapping(int layer2[]);
		void layer3Mapping(int layer3[]);

		void renderLayer1();
		void renderLayer2();
		void renderLayer3();

		void obstacleMapping(int obstacle[]);

};

/*

					NOTE

	The numbering used in layers must be the exact
	number declared fro each tile(image).

	The layering basically acts as which to render
	first then on top of another.

*/

/*

						NOTE

	How you are to send the tile(image) to the class
	is by the same order as it is defined

*/

/*

							NOTE

	Use EMPTY in layers that does not need to have any passthrough
	or tiles that does not have transparent background to fill.

	EMPTY are not typically used in layer1 as most of layer1 are used
	background tiles like grass.

	EMPTY is meant to save performace in upper layers which previous layers
	have been filled.

*/

/*

				NOTE

	There is only a maximum of 3 layers.
	The player is rendered at layer 2.
	Use layer 3 to render things where the
	player can pass through.

*/

/*

					NOTE

	The mapping for obstacle are to be taken
	as all 3 layers combined to one being a
	single completed map

*/

/*

							NOTE

	To check for obstacle collision, get the character and
	check the position (N, NE, E, SE, W, SW, W, NW) 1
	block/node/tile away.

*/