#pragma once

#include "Cell.h"
#include <GL/glut.h>

class Game
{
	public:
		Game();
		virtual~Game();
		int GetGridX();
		int GetGridY();
		void InputGrid();
		void CountNeighbours(int theGridX, int theGridY);
		int IncrementNeighbour(int inputX, int inputY);
		void ChangeState(int theInputX, int theInputY);
		void DrawSquare(int coordX, int coordY);
		void DrawGrid();
		void GameInit();
		void SetRotate(GLfloat inputRotate);


	private:
		int gridX;
		int gridY;
		Cell ** theGrid;
		GLfloat rotate;
};