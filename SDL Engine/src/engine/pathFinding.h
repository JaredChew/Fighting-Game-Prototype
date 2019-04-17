#pragma once

#include <iostream>
#include <vector>

#include "node.h"

#define NONE 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

/*

		NOTE

	To be converted to fit with SDL and movements

*/

class A_Star {

private:

	std::vector<int> path;
	std::vector<int> direction;

	int tileSize; //have not been implemented fully //check if needed
	//int mapSize; //check if needed

	int totalTilesX;
	int totalTilesY;

	int startNodeX;
	int startNodeY;

	int endNodeX;
	int endNodeY;

	int currentNodeX;
	int currentNodeY;

	int pathCount;

	bool pathFound;

public:

	A_Star();
	~A_Star();

	void initPathfinding(std::vector< std::vector<Node> > &node, Node &start, Node &end, A_Star &astr);

	template<typename toMove>
	bool moveOnPath(toMove &character, std::vector< std::vector<Node> > node);

	void getDirection();
	void searchPath(std::vector< std::vector<Node> > &node);
	void resetSearch(std::vector< std::vector<Node> > &node);
	bool checkDirectionPrioirty(std::vector< std::vector<Node> > &node);
	bool checkDirection(std::vector< std::vector<Node> > &node);
	bool checkBoundaries(std::vector< std::vector<Node> > node, int currentNodeX, int currentNodeY);

	void setTileSize(int tileSize);

	void setNumOfTilesX(int totalTilesX);
	void setNumOfTilesY(int totalTilesY);
	void setNumOfTiles(int totalTilesX, int totalTilesY);

	void setStartNodeX(int startNodeX);
	void setStartNodeY(int startNodeY);
	void setStartNodes(int startNodeX, int startNodeY);

	void setEndNodeX(int endNodeX);
	void setEndNodeY(int endNodeY);
	void setEndNodes(int endNodeX, int endNodeY);

};

/*

		NOTE

	[???] moveOnPath() should be done in the stage's class
	[???] moveOnPath() should be done in object(enemy)'s class

*/