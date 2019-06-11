#include "TicTacToeModel.h"
#include <iostream>
#include "TicTacToeBoard.h"
#include "TicTacToeMissionMessageSet.h"

TicTacToeModel::TicTacToeModel()
{
	_board = std::make_unique<TicTacToeBoard>();
	_missionMessageSet = std::make_unique<TicTacToeMissionMessageSet>();
}

TicTacToeModel::~TicTacToeModel()
{
}

const bool TicTacToeModel::PutHorse(const Point & mouseClickPoint, const sf::RenderWindow & window)
{
	WindowSize windowSize = { window.getSize().x, window.getSize().y };
	auto boardSlot = _board->ConvertMouseClickPointToBoardSlot(windowSize, mouseClickPoint);
	auto isPutHorseSuccess = _board->PutHorseOnBoard(_turn, boardSlot);
	if (isPutHorseSuccess)
		_turn = (_turn == HorseType::MARK_O) ? HorseType::MARK_X : HorseType::MARK_O;
	return isPutHorseSuccess;
}

void TicTacToeModel::ShowBoard() const
{
	_board->ShowBoard();
}
