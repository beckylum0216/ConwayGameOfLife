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
{	/*
	for (int ii = 0; ii < NEIGHBOURHOODNUM; ii++)
	{
		delete[] mooreNeighbourhood[ii];
	}

	delete[] mooreNeighbourhood;
	*/
}

void Cell::SetPositionX(int inputX)
{
	positionX = inputX;
}

int Cell::GetPositionX()
{
	return positionX;
}

void Cell::SetPositionY(int inputY)
{
	positionY = inputY;
}

void Cell::SetCellState(bool inputState)
{
	cellState = inputState;
}

bool Cell::GetCellState()
{
	return cellState;
}


void Cell::SetNeighbourhoodCount(int inputCount)
{
	neighbourCount = inputCount;
}

int Cell::GetNeighbourhoodCount()
{
	return neighbourCount;
}