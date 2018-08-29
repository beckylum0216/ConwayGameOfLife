#pragma once

#include "Cell.h"


class Game
{
	public:
		Game();
		virtual~Game();
		void InputGrid();
		bool CheckNeighbourhood();

	private:
		int gridX;
		int gridY;
		Cell ** theGrid;

};