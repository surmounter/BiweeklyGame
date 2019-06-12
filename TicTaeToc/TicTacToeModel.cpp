#include "TicTacToeModel.h"
#include <iostream>
#include <Windows.h>
#include "TicTacToeBoard.h"
#include "TicTacToeMissionMessageSet.h"

#define SELECT_CANCEL_BUTTON 2

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

	if (_board->IsPutHorse(boardSlot) == false)
		return false;
	auto missionMessage = _missionMessageSet->GetMissionMessage();
	if (MessageBoxA(NULL, missionMessage.c_str(), _missionMessageTitle, MB_OKCANCEL | MB_ICONEXCLAMATION) == SELECT_CANCEL_BUTTON)
	{
		ChangeTurn();
		return false;
	}
	_board->PutHorseOnBoard(_turn, boardSlot);		
	ChangeTurn();
	return true;
}

void TicTacToeModel::ShowBoard() const
{
	_board->ShowBoard();
}
