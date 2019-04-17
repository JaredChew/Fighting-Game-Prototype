#include "tileMap.h"

template<int mapSize>
TileMap<mapSize>::TileMap(GameWindow& wnd) : wnd(wnd) {

	tileSize = 0;

	totalTileX = 0;
	totalTileY = 0;

	layer1[mapSize] = { 0 };
	layer2[mapSize] = { 0 };
	layer3[mapSize] = { 0 };

	obstacle[mapSize] = { true };

}

template<int mapSize>
TileMap<mapSize>::~TileMap() { }

template<int mapSize>
void TileMap<mapSize>::scrollMap() {

	//

}

template<int mapSize>
void TileMap<mapSize>::setTile(SDL_Texture* tileImage) { //change to directory ???
	
	AnimatedSprite insert;

	tile.push_back(insert);

	tile[tile.end() - 1].setImage(tileImage); //tile.size() - 1

}

template<int mapSize>
void TileMap<mapSize>::setTileSize(int tileSize) {

	this->tileSize = tileSize;

}

template<int mapSize>
void TileMap<mapSize>::setTileDimensions(int totalTileX, int totalTileY) {

	this->totalTileX = totalTileX;
	this->totalTileY = totalTileY;

}

template<int mapSize>
void TileMap<mapSize>::setTileAnimationProperties(int tile, int maxFrame, int frameDelay, int currentFrame, int frameCounter, bool reverseAnim) {

	this->tile[tile].setAnimationProperties(maxFrame, frameDelay, currentFrame, frameCounter, reverseAnim);

}

template<int mapSize>
void TileMap<mapSize>::layer1Mapping(int layer1[]) {

	for (int i = 0; i < mapSize; i++) {

		this->layer1[i] = layer1[i];

	}

}

template<int mapSize>
void TileMap<mapSize>::layer2Mapping(int layer2[]) {

	for (int i = 0; i < mapSize; i++) {

		this->layer2[i] = layer2[i];

	}

}

template<int mapSize>
void TileMap<mapSize>::layer3Mapping(int layer3[]) {

	for (int i = 0; i < mapSize; i++) {

		this->layer3[i] = layer3[i];

	}

}

template<int mapSize>
void TileMap<mapSize>::renderLayer1() {

	for (int i = 0, x = 0, y = 0; i < mapSize; i++) {

		if (layer1[i] != 0) {

			tile[layer1[i]].setPosX(x * tileSize);
			tile[layer1[i]].setPosY(y * tileSize);

			tile[layer1[i]].display();

		}

		//Check if edge of map
		if (x == (totalTileX - 1)) {
			x = 0; //Reset X axis
			y++; //Adjust Y axis
		}
		else {
			x++;
		}

	}

}

template<int mapSize>
void TileMap<mapSize>::renderLayer2() {

	for (int i = 0, x = 0, y = 0; i < mapSize; i++) {

		if (layer2[i] != 0) {

			tile[layer2[i]].setPosX(x * tileSize);
			tile[layer2[i]].setPosY(y * tileSize);

			tile[layer2[i]].display();

		}

		//Check if edge of map
		if (x == (totalTileX - 1)) {
			x = 0; //Reset X axis
			y++; //Adjust Y axis
		}
		else {
			x++;
		}

	}

}

template<int mapSize>
void TileMap<mapSize>::renderLayer3() {

	for (int i = 0, x = 0, y = 0; i < mapSize; i++) {

		if (layer3[i] != 0) {

			tile[layer3[i]].setPosX(x * tileSize);
			tile[layer3[i]].setPosY(y * tileSize);

			tile[layer3[i]].display();

		}

		//Check if edge of map
		if (x == (totalTileX - 1)) {
			x = 0; //Reset X axis
			y++; //Adjust Y axis
		}
		else {
			x++;
		}

	}

}

template<int mapSize>
void TileMap<mapSize>::obstacleMapping(int obstacle[]) {

	for (int i = 0; i < mapSize; i++) {

		this->obstacle[i] = obstacle[i];

		this->obstacle[i] = !this->obstacle[i];

	}

}
