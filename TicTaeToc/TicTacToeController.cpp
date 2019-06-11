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
void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const Point & mouseClickPoint) const
{
	std::cout << "On Click MouseButton : " << mouseClickPoint.GetX() << "," << mouseClickPoint.GetY() << std::endl;
	TicTacToeModel model;
	model.PutHorse(mouseClickPoint, window);
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
