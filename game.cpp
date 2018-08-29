
#include <iostream>
#include "Game.h"
#include "Cell.h"

void Game::Game()
{
	inputGrid();



}

void Game::~Game()
{

}

void Game::InputGrid()
{
	std::cout << "Please enter the width of the grid" << std::endl;
	std:cin >> gridX;
	std::cout << "Please enter the height of the grid" << std::endl;
	std::cin >> gridY;
}

bool Game::CheckState(Cell theCell)
{
	

}

