#pragma once

#include <pch.h>
#include "Cellz.h"
#include <GL/glut.h>

struct Pair
{
	int x;
	int y;
};

class Game
{
	public:
		Game();
		virtual~Game();
		int GetGridX();
		int GetGridY();
		void InputGrid();
		int CountNeighbours(int theGridX, int theGridY);
		Pair WrapCoords(int theGridX, int theGridY);
		void ChangeState(int theInputX, int theInputY);
		void DrawSquare(int coordX, int coordY, GLfloat theWidth, GLfloat theHeight);
		void DrawGrid(GLfloat winWidth, GLfloat winHeight);
		void GameInit();
		void NewFrame();
		void SetRotate(GLfloat inputRotate);


	private:
		int gridX;
		int gridY;
		Cellz ** theGrid;
		GLfloat rotate;
};