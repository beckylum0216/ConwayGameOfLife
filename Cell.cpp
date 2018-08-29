#include "Cell.h"
#include "GameManager.h"

Cell::Cell()
{
	/*
	mooreNeighbourhood = new bool *[NEIGHBOURHOODNUM];
	for (int ii = 0; ii < NEIGHBOURHOODNUM; ii++)
	{
		mooreNeighbourhood[ii] = new bool[NEIGHBOURHOODNUM];
	}
	*/
}

Cell::~Cell()
{
	for (int ii = 0; ii < NEIGHBOURHOODNUM; ii++)
	{
		delete[] mooreNeighbourhood[ii];
	}

	delete[] mooreNeighbourhood;
}




void Cell::SetCellState(bool inputState)
{
	cellState = inputState;
}

//Any live cell with fewer than two live neighbours dies(referred to as underpopulation or exposure[1]).
//Any live cell with more than three live neighbours dies(referred to as overpopulation or overcrowding).
//Any live cell with two or three live neighbours lives, unchanged, to the next generation.
//Any dead cell with exactly three live neighbours will come to life.

void Cell::SetCellState()
{

}

void Cell::SetNeighbourhoodCount(int inputCount)
{
	for (int ii = 0; ii < NEIGHBOURHOODNUM; ii++)
	{
		for (int jj = 0; jj < NEIGHBOURHOODNUM; jj++)
		{
			if (!((ii % 2 == 0) && (jj % 2 == 0)))
			{
				if (mooreNeighbourhood[positionX - 1][positionY - 1])
			}
		}
	}
}