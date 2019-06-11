#include "TicTacToeController.h"
#include <iostream>

TicTacToeController::TicTacToeController()
{
}

TicTacToeController::~TicTacToeController()
{
}


void TicTacToeController::OnStartGameLoop(sf::RenderWindow & window) const
{
	std::cout << "On Start Game Loop" << std::endl;	
}

#include "TicTacToeModel.h"
void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const MouseCoord mouseCoord) const
{
	std::cout << "On Click MouseButton : " << mouseCoord.first << "," << mouseCoord.second << std::endl;
	TicTacToeModel model;
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
