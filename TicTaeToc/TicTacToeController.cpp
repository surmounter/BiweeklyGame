#include "TicTacToeController.h"
#include <iostream>

TicTacToeController::TicTacToeController()
{
}

TicTacToeController::~TicTacToeController()
{
}

#include "TicTacToeBoard.h"
void TicTacToeController::OnStartGameLoop(sf::RenderWindow & window) const
{
	std::cout << "On Start Game Loop" << std::endl;	
}

void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const MouseCoord mouseCoord) const
{
	std::cout << "On Click MouseButton : " << mouseCoord.first << "," << mouseCoord.second << std::endl;
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
