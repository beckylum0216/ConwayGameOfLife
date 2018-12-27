#include <iostream>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

#include <pch.h>
#include <Cellz.h>
#include "Game.h"


Game::Game()
{
	InputGrid();
	theGrid = new Cellz *[gridX];
	for (int ii = 0; ii < gridX; ii++)
	{
		theGrid[ii] = new Cellz[gridY];
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

int Game::CountNeighbours(int theGridX, int theGridY )
{
	//std::cout << "@@@Running Check Neighbourhood@@@" << std::endl;
	int theNeighbours = 0;

	// 3 x 3 grid centred on theGridX,theGridY
	for (int xx = theGridX - 1; xx <= theGridX + 1; ++xx)
	{
		for (int yy = theGridY - 1; yy <= theGridY + 1; ++yy)
		{
			if ((xx == theGridX) && (yy == theGridY))
			{
				// Current cell - ignore.
			}
			else
			{
				Pair newCoords = WrapCoords(xx, yy);
				if (theGrid[newCoords.x][newCoords.y].GetCellState())
				{
					theNeighbours++;
				}
					
			}
		}
	}

	return theNeighbours;



}

Pair Game::WrapCoords(int theGridX, int theGridY)
{
	Pair newCoords;
	newCoords.x = theGridX;
	newCoords.y = theGridY;

	if (theGridX < 0)
	{
		newCoords.x = gridX - 1;
	}
		
	if (theGridX >= gridX)
	{
		newCoords.x = 0;
	}
		
	if (theGridY < 0)
	{
		newCoords.y = gridY - 1;
	}
		
	if (theGridY >= gridY)
	{
		newCoords.y = 0;
	}
		
	return newCoords;
}


//Any live cell with fewer than two live neighbours dies(referred to as underpopulation or exposure[1]).
//Any live cell with more than three live neighbours dies(referred to as overpopulation or overcrowding).
//Any live cell with two or three live neighbours lives, unchanged, to the next generation.
//Any dead cell with exactly three live neighbours will come to life.

void Game::NewFrame()
{
	for (int ii = 0; ii < gridX; ++ii)
	{
		for (int jj = 0; jj < gridY; ++jj)
		{
			theGrid[ii][jj].SetCellState(theGrid[ii][jj].GetNextState());
		}
	}
		
}

void Game::ChangeState(int theInputX, int theInputY)
{	
	// Change the state of a given cell based on how many neighbours are alive
	int theNeighbours = CountNeighbours(theInputX, theInputY);

	if (theGrid[theInputX][theInputY].GetCellState())
	{
		if (theNeighbours < 2 )
		{
			theGrid[theInputX][theInputY].SetNextState(false);
		}
		else if (theNeighbours > 3)
		{
			theGrid[theInputX][theInputY].SetNextState(false);
		}
		else 
		{
			theGrid[theInputX][theInputY].SetNextState(true);
		}
		
	}
	else 
	{
		if (theNeighbours == 3)
		{
			theGrid[theInputX][theInputY].SetNextState(true);
		}
	}

	
	//std::cout << "===Change state result===" << std::endl;
	/*
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			std::cout << "X: " << ii << " Y: " << jj << "State: " << theGrid[ii][jj].GetCellState() << " Next State:" << theGrid[ii][jj].GetNextState() << std::endl;
		}

	}
	*/
	//std::cout << "===Change state result===" << std::endl;
	

}

void Game::DrawSquare(int coordX, int coordY, GLfloat theWidth, GLfloat theHeight)
{
	GLfloat drawX = 0.0;
	GLfloat drawY = 0.0;

	drawX = (GLfloat)coordX;
	drawY = (GLfloat)coordY;

	if (theGrid[coordX][coordY].GetCellState() == false)
	{

		glPushMatrix();
		//glRotatef(180.0, 0.00, 1.00, 0.00);
			glBegin(GL_QUADS);
				glColor3f(0.314f, 0.114f, 1.0f);    // Color Blue    
				glVertex3f(drawX/theWidth, drawY / theHeight, 1.0f);    // Top Right Of The Quad (Front)
				glVertex3f(drawX/theWidth, (drawY + 1)/theHeight, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f((drawX + 1)/theWidth, (drawY + 1)/theHeight, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f((drawX + 1)/theWidth, drawY/theHeight, 1.0f);		// Bottom Right Of The Quad (Front)
			glEnd();
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		//glRotatef(180.0, 0.00, 1.00, 0.00);
			glBegin(GL_QUADS);
				glColor3f(1.0f, 0.996f, 0.643f);    // Color Yellow   
				glVertex3f(drawX / theWidth, drawY / theHeight, 1.0f);    // Top Right Of The Quad (Front)
				glVertex3f(drawX / theWidth, (drawY + 1) / theHeight, 1.0f);    // Top Left Of The Quad (Front)
				glVertex3f((drawX + 1) / theWidth, (drawY + 1) / theHeight, 1.0f);    // Bottom Left Of The Quad (Front)
				glVertex3f((drawX + 1) / theWidth, drawY / theHeight, 1.0f);		// Bottom Right Of The Quad (Front)
			glEnd();
		glPopMatrix();
	}

}

void Game::DrawGrid(GLfloat winWidth, GLfloat winHeight)
{
	//std::cout << "---Drawing Grid---" << std::endl;
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			//CheckNeighbourhood(ii, jj);
			//ChangeState(ii, jj);
			
			//std::cout << "X: " << ii << " Y: " << jj << " State: " << theGrid[ii][jj].GetCellState() << " Next State:" << theGrid[ii][jj].GetNextState() << std::endl;
			
			
			DrawSquare(ii, jj, winWidth, winHeight);
			
		}
	}
	//std::cout << "---Drawing Grid---" << std::endl;
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
	theGrid[5][5].SetNextState(true);
	theGrid[5][6].SetNextState(true);
	theGrid[5][7].SetNextState(true);

	std::cout << "Run random seeding" << std::endl;
	// random cell seeding
	for (int ii = 0; ii < 3000; ii++)
	{
		int cellX;
		int cellY;

		cellX = rand() % gridX;
		cellY = rand() % gridY;

		std::cout << "cellX: " << cellX << " cellY: " << cellY << std::endl;

		theGrid[cellX][cellY].SetPositionX(cellX);
		theGrid[cellX][cellY].SetPositionY(cellY);
		theGrid[cellX][cellY].SetCellState(true);
		theGrid[cellX][cellY].SetNextState(true);
	}
	std::cout << "Finished random seeding" << std::endl;

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
