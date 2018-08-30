#pragma once

#include "Cell.h"


class Game
{
	public:
		Game();
		virtual~Game();
		void InputGrid();
		void CheckNeighbourhood(int theGridX, int theGridY);
		int IncrementNeighbour(int inputX, int inputY);
		void ChangeState(int theInputX, int theInputY);
		void DrawSquare(int coordX, int coordY);
		void DrawGrid();
		void GameInit();



	private:
		int gridX;
		int gridY;
		Cell ** theGrid;

};