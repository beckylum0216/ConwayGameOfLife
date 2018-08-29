#pragma once



class Game
{
	public:
		Game();
		virtual~Game();
		void InputGrid();

	private:
		int gridX;
		int gridY;

};