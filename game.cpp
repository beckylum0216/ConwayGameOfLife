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

	rotate = 0;
}



Game::~Game()
{
	for (int ii = 0; ii < gridY; ii++)
	{
		delete[] theGrid[ii];
	}

	delete[] theGrid;
}

int Game::GetGridX()
{
	return gridX;
}

int Game::GetGridY()
{
	return gridY;
}

void Game::InputGrid()
{
	std::cout << "Please enter the width of the grid" << std::endl;
	std::cin >> gridX;
	std::cout << "Please enter the height of the grid" << std::endl;
	std::cin >> gridY;
}

void Game::CountNeighbours(int theGridX, int theGridY )
{
	//std::cout << "@@@Running Check Neighbourhood@@@" << std::endl;
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

	
	std::cout << "X: " << theGridX << " Y: " << theGridY << " Count: " << theNeighbours;
	theGrid[theGridX][theGridY].SetNeighbourhoodCount(theNeighbours);
	//std::cout << "X: " << theGridX << " Y: " << theGridY << " Count: " << theGrid[theGridX][theGridY].GetNeighbourhoodCount() << std::endl;
	//std::cout << "@@@Running Check Neighbourhood@@@" << std::endl;
}

int Game::IncrementNeighbour(int inputX, int inputY)
{
	int tempNeighbours = 0;
	int wrapX = 0;
	int wrapY = 0;

	if (inputX == -1)
	{
		wrapX = gridX - 1;
	}
	else if (inputX == gridX)
	{
		wrapX = 0;
	}
	else
	{
		wrapX = inputX;
	}

	if (inputY == -1)
	{
		wrapY = gridY - 1;
	}
	else if (inputY == gridY)
	{
		wrapY = 0;
	}
	else
	{
		wrapY = inputY;
	}

	// to wrap the check around the grid
	//wrapX = abs(inputX) % gridX; // not so sure about this absolute
	//wrapY = abs(inputY) % gridY; // not so sure about this absolute

	if (theGrid[wrapX][wrapY].GetCellState() == true)
	{
		tempNeighbours = 1;
	}
	else
	{
		tempNeighbours = 0;
	}

	//std::cout << "X: " << wrapX << " Y: " << wrapY << " Temp Neighbour: " << tempNeighbours << std::endl;
	return tempNeighbours;
}

//Any live cell with fewer than two live neighbours dies(referred to as underpopulation or exposure[1]).
//Any live cell with more than three live neighbours dies(referred to as overpopulation or overcrowding).
//Any live cell with two or three live neighbours lives, unchanged, to the next generation.
//Any dead cell with exactly three live neighbours will come to life.

void Game::ChangeState(int theInputX, int theInputY)
{	
	//Change states for next iteration
	theGrid[theInputX][theInputY].SetCellState(theGrid[theInputX][theInputY].GetNextState());
	// Set next state to current
	theGrid[theInputX][theInputY].SetNextState(theGrid[theInputX][theInputY].GetCellState());
	
	CountNeighbours(theInputX, theInputY);

	if (theGrid[theInputX][theInputY].GetCellState())
	{
		if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() < 2 )
		{
			theGrid[theInputX][theInputY].SetNextState(false);
		}
		
		if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() > 3)
		{
			theGrid[theInputX][theInputY].SetNextState(false);
		}
		
		if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() >= 2 || 
			theGrid[theInputX][theInputY].GetNeighbourhoodCount() <= 3)
		{
			theGrid[theInputX][theInputY].SetNextState(true);
		}
		
	}
	else 
	{
		if (theGrid[theInputX][theInputY].GetNeighbourhoodCount() == 3)
		{
			theGrid[theInputX][theInputY].SetNextState(true);
		}
	}

	
	std::cout << "===Change state result===" << std::endl;
	/*
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			std::cout << "X: " << ii << " Y: " << jj << "State: " << theGrid[ii][jj].GetCellState() << " Next State:" << theGrid[ii][jj].GetNextState() << std::endl;
		}

	}
	*/
	std::cout << "===Change state result===" << std::endl;
	

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
				glVertex3f(drawX, drawY + 1, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f(drawX + 1, drawY + 1, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f(drawX + 1, drawY, 1.0f);		// Bottom Right Of The Quad (Front)
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
				glVertex3f(drawX, drawY+1, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f(drawX+1,drawY+1, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f(drawX+1, drawY, 1.0f);		// Bottom Right Of The Quad (Front)
			glEnd();
		glPopMatrix();
	}

}

void Game::DrawGrid()
{
	std::cout << "---Drawing Grid---" << std::endl;
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			//CheckNeighbourhood(ii, jj);
			//ChangeState(ii, jj);
			
			//std::cout << "X: " << ii << " Y: " << jj << " State: " << theGrid[ii][jj].GetCellState() << " Next State:" << theGrid[ii][jj].GetNextState() << std::endl;
			DrawSquare(ii, jj);
			
		}
	}
	std::cout << "---Drawing Grid---" << std::endl;
}

void Game::GameInit()
{
	//std::cout << "Initialising..." << std::endl;

	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			theGrid[ii][jj].SetPositionX(ii);
			theGrid[ii][jj].SetPositionY(jj);
			theGrid[ii][jj].SetCellState(false);
			theGrid[ii][jj].SetNeighbourhoodCount(0);
			theGrid[ii][jj].SetNextState(false);
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
	theGrid[5][5].SetNextState(true);
	theGrid[5][6].SetNextState(true);
	theGrid[5][7].SetNextState(true);

	/*
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			//ChangeState(ii, jj);
			std::cout << "X: " << ii << " Y: " << jj << "State: " << theGrid[ii][jj].GetCellState() << " Next State:"  << theGrid[ii][jj].GetNextState() <<std::endl;
		}

	}
	*/
	//std::cout << "Finished Initialising..." << std::endl;
}

void Game::SetRotate(GLfloat inputRotate)
{
	rotate += inputRotate;
}
