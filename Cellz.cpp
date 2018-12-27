#include <pch.h>
#include <Cellz.h>


Cellz::Cellz()
{
	positionX = 0;
	positionY = 0;
	cellState = false;
	nextState = false;
}

Cellz::~Cellz()
{

}

void Cellz::SetPositionX(int inputX)
{
	positionX = inputX;
}

int Cellz::GetPositionX()
{
	return positionX;
}

void Cellz::SetPositionY(int inputY)
{
	positionY = inputY;
}

int Cellz::GetPositionY()
{
	return positionY;
}

void Cellz::SetCellState(bool inputState)
{
	cellState = inputState;
}

bool Cellz::GetCellState()
{
	return cellState;
}


void Cellz::SetNextState(bool inputNextState)
{
	nextState = inputNextState;
}

bool Cellz::GetNextState()
{
	return nextState;
}