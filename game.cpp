#include <iostream>
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

}

Game::~Game()
{
	for (int ii = 0; ii < gridX; ii++)
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

bool Game::CheckNeighbourhood()
{
	for (int ii = 0; ii < gridX; ii++)
	{
		for (int jj = 0; jj < gridY; jj++)
		{
			if (theGrid[gridX - 1][gridY - 1].GetCellState == true)
			{

			}
		}
	}

}

