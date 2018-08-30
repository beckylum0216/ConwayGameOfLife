#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

#include "Game.h"
#include "Cell.h"

Game::Game()
{
	InputGrid();
	theGrid = new Cell *[gridX];
	for (int ii = 0; ii < gridX; ii++)
	{
		theGrid[ii] = new Cell[gridY];

	}

	/*
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			theGrid[ii][jj].SetPositionX(ii);
			theGrid[ii][jj].SetPositionY(jj);
			theGrid[ii][jj].SetCellState(false);
			theGrid[ii][jj].SetNeighbourhoodCount(0);
		}
	}
	*/
}



Game::~Game()
{
	for (int ii = 0; ii < gridY; ii++)
	{
		delete[] theGrid[ii];
	}

	delete[] theGrid;
}

void Game::InputGrid()
{
	std::cout << "Please enter the width of the grid" << std::endl;
	std::cin >> gridX;
	std::cout << "Please enter the height of the grid" << std::endl;
	std::cin >> gridY;
}

void Game::CheckNeighbourhood(int theGridX, int theGridY )
{
	int theNeighbours = 0;

	//moore's neighbourhood check
	theNeighbours += IncrementNeighbour(theGridX - 1, theGridY - 1); //top left-hand corner
	theNeighbours += IncrementNeighbour(theGridX, theGridY - 1); // top of target 
	theNeighbours += IncrementNeighbour(theGridX + 1, theGridY - 1); // top right-hand corner
	theNeighbours += IncrementNeighbour(theGridX + 1, theGridY); // right of target
	theNeighbours += IncrementNeighbour(theGridX + 1, theGridY + 1); // bottom right-hand corner
	theNeighbours += IncrementNeighbour(theGridX, theGridY + 1); // bottom of target
	theNeighbours += IncrementNeighbour(theGridX - 1, theGridY + 1); // bottom left-hand corner
	theNeighbours += IncrementNeighbour(theGridX - 1, theGridY); // left of target

	theGrid[theGridX][theGridY].SetNeighbourhoodCount(theNeighbours);
}

int Game::IncrementNeighbour(int inputX, int inputY)
{
	int tempNeighbours = 0;
	int wrapX = 0;
	int wrapY = 0;

	// to wrap the check around the grid
	wrapX = abs(inputX) % gridX; // not so sure about this absolute
	wrapY = abs(inputY) % gridY; // not so sure about this absolute


	if (theGrid[wrapX][wrapY].GetCellState() == true)
	{
		tempNeighbours = 1;
	}
	else
	{
		tempNeighbours = 0;
	}

	return tempNeighbours;
}

//Any live cell with fewer than two live neighbours dies(referred to as underpopulation or exposure[1]).
//Any live cell with more than three live neighbours dies(referred to as overpopulation or overcrowding).
//Any live cell with two or three live neighbours lives, unchanged, to the next generation.
//Any dead cell with exactly three live neighbours will come to life.

void Game::ChangeState(int theInputX, int theInputY)
{

	if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() < 2)
	{
		theGrid[theInputX][theInputY].SetCellState(false);
	}
	else if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() > 3)
	{
		theGrid[theInputX][theInputY].SetCellState(false);
	}
	else if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() == 3)
	{
		theGrid[theInputX][theInputY].SetCellState(true);
	}
	else
	{
		theGrid[theInputX][theInputY].SetCellState(theGrid[theInputX][theInputY].GetCellState());
	}
}

void Game::DrawSquare(int coordX, int coordY)
{
	GLfloat drawX = 0.0;
	GLfloat drawY = 0.0;

	drawX = (GLfloat)coordX;
	drawY = (GLfloat)coordY;

	if (theGrid[coordX][coordY].GetCellState() == false)
	{

		glPushMatrix();
		glRotatef(180.0, 0.00, 1.00, 0.00);
			glBegin(GL_QUADS);
				glColor3f(0.314f, 0.114f, 1.0f);    // Color Blue    
				glVertex3f(drawX, drawY, 1.0f);    // Top Right Of The Quad (Front)
				glVertex3f(-drawX, drawY, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f(-drawX, -drawY, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f(drawX, -drawY, 1.0f);		// Bottom Right Of The Quad (Front)
			glEnd();
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glRotatef(180.0, 0.00, 1.00, 0.00);
			glBegin(GL_QUADS);
				glColor3f(1.0f, 0.996f, 0.643f);    // Color Yellow   
				glVertex3f(drawX, drawY, 1.0f);    // Top Right Of The Quad (Front)
				glVertex3f(-drawX, drawY, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f(-drawX, -drawY, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f(drawX, -drawY, 1.0f);		// Bottom Right Of The Quad (Front)
			glEnd();
		glPopMatrix();
	}

}

void Game::DrawGrid()
{
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			CheckNeighbourhood(ii, jj);
			ChangeState(ii, jj);
			DrawSquare(ii, jj);
		}
	}
}

void Game::GameInit()
{

	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			theGrid[ii][jj].SetPositionX(ii);
			theGrid[ii][jj].SetPositionY(jj);
			theGrid[ii][jj].SetCellState(false);
			theGrid[ii][jj].SetNeighbourhoodCount(0);
		}
	}

	// initial blinker
	theGrid[5][5].SetPositionX(5);
	theGrid[5][6].SetPositionX(5);
	theGrid[5][7].SetPositionX(5);
	theGrid[5][5].SetPositionY(5);
	theGrid[5][6].SetPositionY(6);
	theGrid[5][7].SetPositionY(7);
	theGrid[5][5].SetCellState(true);
	theGrid[5][6].SetCellState(true);
	theGrid[5][7].SetCellState(true);
	theGrid[5][5].SetNeighbourhoodCount(1);
	theGrid[5][6].SetNeighbourhoodCount(2);
	theGrid[5][7].SetNeighbourhoodCount(1);
}


