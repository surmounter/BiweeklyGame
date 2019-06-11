#include "TicTacToeModel.h"
#include "TicTacToeBoard.h"
#include "TicTacToeMissionMessageSet.h"

TicTacToeModel::TicTacToeModel()
{
}

TicTacToeModel::~TicTacToeModel()
{
}

const bool TicTacToeModel::PutHorse(const Point & mouseClickPoint, const sf::RenderWindow & window)
{
	WindowSize windowSize = { window.getSize().x, window.getSize().y };
	auto boardSlot = _board->ConvertMouseCoordToBoardCoord(windowSize, mouseClickPoint);
	auto isPutHorseSuccess = _board->MarkBoard(_turn, boardSlot);
	return isPutHorseSuccess;
}
