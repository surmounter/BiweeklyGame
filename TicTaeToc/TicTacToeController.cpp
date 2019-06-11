#include "TicTacToeController.h"
#include <iostream>
#include "TicTacToeModel.h"

TicTacToeController::TicTacToeController()
{
	_model = std::make_unique<TicTacToeModel>();
}

TicTacToeController::~TicTacToeController()
{
}

void TicTacToeController::OnStartGameLoop(sf::RenderWindow & window) const
{
	std::cout << "On Start Game Loop" << std::endl;	
}

void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const Point & mouseClickPoint) const
{
	std::cout << "On Click MouseButton : " << mouseClickPoint.GetX() << "," << mouseClickPoint.GetY() << std::endl;
	_model->PutHorse(mouseClickPoint, window);
	_model->ShowBoard();
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
