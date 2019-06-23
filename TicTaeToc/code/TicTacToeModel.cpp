#include "TicTacToeModel.h"
#include <iostream>
#include <Windows.h>
#include "TicTacToeBoard.h"
#include "TicTacToeMissionMessageSet.h"
#include "TicTacToeAudioMgr.h"
#include "TicTacToeAudioKind.h"
TicTacToeModel::TicTacToeModel()
{
	_board = std::make_unique<TicTacToeBoard>();
	_missionMessageSet = std::make_unique<TicTacToeMissionMessageSet>();
	_audioMgr = std::make_unique<TicTacToeAudioMgr>();
}

TicTacToeModel::~TicTacToeModel()
{
}

void TicTacToeModel::Initialize()
{
	_board->ClearBoard();
	_missionMessageSet->InitializeMissionMessageSet();
	_turn = HorseType::MARK_O;
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
	_audioMgr->Play(TicTacToeAudioKind::PUTHORSE);
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

const TicTacToeGameResult::Value TicTacToeModel::GetGameResult() const
{
	return _board->GetGameResult();
}

const bool TicTacToeModel::AskRestart(const TicTacToeGameResult::Value gameResult) const
{
	const int clickRetryButton = 4;
	const bool isRestart = (MessageBoxA(NULL, _askRestartContents, GetAskRestartTitle(gameResult).c_str(), MB_RETRYCANCEL | MB_ICONINFORMATION) == clickRetryButton);
	return isRestart;
}

const bool TicTacToeModel::TryMission() const
{
	auto missionMessage = _missionMessageSet->GetMissionMessage();
	const int clickYesButton = 6;
	const bool isClear = (MessageBoxA(NULL, missionMessage.c_str(), _missionMessageTitle, MB_YESNO | MB_ICONEXCLAMATION) == clickYesButton);
	return isClear;
}

const std::string TicTacToeModel::GetAskRestartTitle(const TicTacToeGameResult::Value gameResult) const
{
	std::string askRestartTitle;
	switch (gameResult)
	{
	case TicTacToeGameResult::DRAW:
		askRestartTitle = "GameResult is DRAW";
		break;
	case TicTacToeGameResult::WINNER_MARK_O:
		askRestartTitle = "Winner is PlayerO";
		break;
	case TicTacToeGameResult::WINNER_MARK_X:
		askRestartTitle = "Winner is PlayerX";
		break;
	default:
		break;			
	}
	return askRestartTitle;
}
