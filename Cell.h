#pragma once

class Cell
{
	public:
		Cell();
		virtual~Cell();
		void SetPositionX(int inputX);
		int GetPositionX();
		void SetPositionY(int inputY);
		int GetPositionY();
		void SetCellState(bool inputState);
		bool GetCellState();
		void SetNeighbourhoodCount(int inputCount);
		int GetNeighbourhoodCount();
		void SetNextState(bool inputNextState);
		bool GetNextState();

	private:
		int positionX;
		int positionY;
		bool cellState;
		int neighbourCount;
		bool nextState;

};