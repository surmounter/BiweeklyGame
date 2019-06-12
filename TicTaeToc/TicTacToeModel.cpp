#include "TicTacToeModel.h"
#include <iostream>
#include <Windows.h>
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

	if (_board->IsPutHorse(boardSlot) == false)
		return false;	
	ChangeTurn();
	if (TryMission() == false)
		return false;
	_board->PutHorseOnBoard(_turn, boardSlot);		
	return true;
}

void TicTacToeModel::ShowBoard() const
{
	_board->ShowBoard();
}

const bool TicTacToeModel::TryMission() const
{
	auto missionMessage = _missionMessageSet->GetMissionMessage();
	const int clickOkButton = 1;
	const bool isClear = (MessageBoxA(NULL, missionMessage.c_str(), _missionMessageTitle, MB_OKCANCEL | MB_ICONEXCLAMATION) == clickOkButton);
	return isClear;
}
