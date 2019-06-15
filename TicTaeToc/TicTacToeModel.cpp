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

	if (_board->CanPutHorse(boardSlot) == false)
		return false;	
	if (TryMission() == false)
	{
		ChangeTurn();
		return false;
	}
	_board->PutHorseOnBoard(_turn, boardSlot);		
	ChangeTurn();
	return true;
}

void TicTacToeModel::ShowResultOfTurn() const
{
	std::cout << "present turn : " << _turn << std::endl;
	_board->ShowBoard();
}

const int TicTacToeModel::GetBoardSlotCnt() const
{
	return _board->GetBoardSlotCnt();
}

const Board TicTacToeModel::GetBoard() const
{
	return _board->GetBoard();
}

const HorseType::value TicTacToeModel::isWin() const
{
	return _board->GetGameResult();
}

const bool TicTacToeModel::TryMission() const
{
	auto missionMessage = _missionMessageSet->GetMissionMessage();
	const int clickOkButton = 1;
	const bool isClear = (MessageBoxA(NULL, missionMessage.c_str(), _missionMessageTitle, MB_OKCANCEL | MB_ICONEXCLAMATION) == clickOkButton);
	return isClear;
}
