#pragma once

#include <pch.h>

class Cellz
{
	public:
		Cellz();
		virtual~Cellz();
		void SetPositionX(int inputX);
		int GetPositionX();
		void SetPositionY(int inputY);
		int GetPositionY();
		void SetCellState(bool inputState);
		bool GetCellState();
		void SetNextState(bool inputNextState);
		bool GetNextState();

	private:
		int positionX;
		int positionY;
		bool cellState;
		bool nextState;

};