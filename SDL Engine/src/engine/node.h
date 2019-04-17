#pragma once

class Node {

	private:

		int x;
		int y;

		int nodeSize; //check if needed

		bool openNode;
		bool visited;
		bool passable;

	public:

		Node();
		~Node();

		void setNodePositions(int x, int y);

		void setX(int x);
		void setY(int y);

		int getX();
		int getY();

		void setOpenNode(bool openNode);
		void setVisited(bool visited);
		void setPassable(bool passable);

		bool getOpenNode();
		bool getVisited();
		bool getPassable();

};