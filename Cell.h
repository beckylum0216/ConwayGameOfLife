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
		void SetNeighbourhoodCount();
		int GetNeighbourhoodCount();

	private:
		int positionX;
		int positionY;
		bool cellState;
		int neighbourCount;

};