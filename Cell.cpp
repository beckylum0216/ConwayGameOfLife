#include "Cell.h"
#include "GameManager.h"

Cell::Cell()
{
	positionX = 0;
	positionY = 0;
	cellState = false;
	neighbourCount = 0;
	nextState = false;
}

Cell::~Cell()
{	

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

void Cell::SetNextState(bool inputNextState)
{
	nextState = inputNextState;
}

bool Cell::GetNextState()
{
	return nextState;
}