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
	TicTacToeBoard b;
	WindowSize w = { window.getSize().x, window.getSize().y };
	Coord m = { 600, 600 };
	auto ret = b.ConvertMouseCoordToBoardCoord(w,m);
	std::cout << ret.x << "," << ret.y;
}

void TicTacToeController::OnClickMouseButton(sf::RenderWindow & window, const MouseCoord mouseCoord) const
{
	std::cout << "On Click MouseButton : " << mouseCoord.first << "," << mouseCoord.second << std::endl;
}

void TicTacToeController::OnCloseWindow() const
{
	std::cout << "On Close Window" << std::endl;
}
