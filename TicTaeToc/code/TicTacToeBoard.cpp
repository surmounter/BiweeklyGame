#include "TicTacToeBoard.h"
#include <algorithm>
#include <string.h>
#include <iostream>
#include <cassert>

TicTacToeBoard::TicTacToeBoard()
{
	ClearBoard();
}

TicTacToeBoard::~TicTacToeBoard()
{
}

void TicTacToeBoard::ClearBoard()
{
	for(int y = 0; y < rowCnt; ++y)
		std::fill(_board[y].begin(), _board[y].end(), HorseType::EMPTY);
}

const bool TicTacToeBoard::PutHorseOnBoard(const HorseType::value horseType, const BoardSlot & boardSlot)
{
	if (CanPutHorse(boardSlot) == false)
		return false;
	_board[boardSlot.y][boardSlot.x] = horseType;
	return true;
}

const BoardSlot TicTacToeBoard::ConvertMouseClickPointToBoardSlot(const WindowSize & windowSize, const Point & mouseClickPoint) const
{
	assert(rowCnt > 0 && colCnt > 0, "Error will occur because divide by zero");
	BoardSlot boardSlot;
	boardSlot.x = mouseClickPoint.GetX() / (windowSize.width / rowCnt);
	boardSlot.y = mouseClickPoint.GetY() / (windowSize.height / colCnt);
	if (boardSlot.x >= rowCnt) boardSlot.x = rowCnt - 1;
	if (boardSlot.y >= colCnt) boardSlot.y = colCnt - 1;
	return boardSlot;
}

void TicTacToeBoard::ShowBoard() const
{
	for (int y = 0; y < rowCnt; ++y)
	{
		for (int x = 0; x < colCnt; ++x)
			std::cout << _board[y][x] << " ";
		std::cout << std::endl;
	}
}

const bool TicTacToeBoard::CanPutHorse(const BoardSlot & boardSlot) const
{
	if (IsEmpty(boardSlot) == false || IsOffBoard(boardSlot))
		return false;
	return true;
}

const int TicTacToeBoard::GetBoardSlotCnt() const
{
	assert(_board.size() > 0 && _board[0].size() > 0, "board is empty");
	return _board.size() * _board[0].size();
}

const Board TicTacToeBoard::GetBoard() const
{
	return _board;
}

const TicTacToeGameResult::Value TicTacToeBoard::GetGameResult() const
{
	assert(_board.size() > 0 && _board[0].size() > 0, "board is empty");
	if (isAllBoardSlotOccupied()) return TicTacToeGameResult::DRAW;
	
	TicTacToeGameResult::Value gameResult;
	if ((gameResult = CheckIfHorsesAreSameInRows()) != TicTacToeGameResult::NONE) return gameResult;
	if ((gameResult = CheckIfHorsesAreSameInColumes()) != TicTacToeGameResult::NONE) return gameResult;
	if ((gameResult = ChckeIfHorseAreSameInDiagonals()) != TicTacToeGameResult::NONE) return gameResult;
	if ((gameResult = ChckeIfHorseAreSameInAntiDiagonals()) != TicTacToeGameResult::NONE) return gameResult;

	return TicTacToeGameResult::NONE;
}

const TicTacToeGameResult::Value TicTacToeBoard::CheckIfHorsesAreSameInRows() const
{
	for (int y = 0; y < rowCnt; ++y)
	{
		int x = 0;
		for (; x < colCnt; ++x)
			if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[y][0])
				break;
		const bool isSameInYRow = (x == colCnt);
		if (isSameInYRow) return static_cast<TicTacToeGameResult::Value>(_board[y][0]);
	}
	return TicTacToeGameResult::NONE;
}

const TicTacToeGameResult::Value TicTacToeBoard::CheckIfHorsesAreSameInColumes() const
{
	for (int x = 0; x < colCnt; ++x)
	{
		int y = 0;
		for (; y < rowCnt; ++y)
			if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[0][x])
				break;
		const bool isSameInXCol = (y == rowCnt);
		if (isSameInXCol) return static_cast<TicTacToeGameResult::Value>(_board[0][x]);
	}
	return TicTacToeGameResult::NONE;
}

const TicTacToeGameResult::Value TicTacToeBoard::ChckeIfHorseAreSameInDiagonals() const
{
	int i = 0;
	for (; i < _board.size(); ++i)
	{
		if (_board[i][i] == HorseType::EMPTY || _board[i][i] != _board[0][0])
			break;
	}
	const bool isSameInDiagonal = (i == _board.size());
	if (isSameInDiagonal) 
		return static_cast<TicTacToeGameResult::Value>(_board[0][0]);
	return TicTacToeGameResult::NONE;
}

const TicTacToeGameResult::Value TicTacToeBoard::ChckeIfHorseAreSameInAntiDiagonals() const
{
	int y = 0;
	int x = colCnt - 1;
	for (; x >= 0 && y < rowCnt; --x, ++y)
		if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[0][colCnt - 1])
			break;
	const bool isSameInAntiDiagonal = (x == -1 && y == rowCnt);
	if (isSameInAntiDiagonal) 
		return static_cast<TicTacToeGameResult::Value>(_board[0][colCnt - 1]);
	return TicTacToeGameResult::NONE;
}

const bool TicTacToeBoard::isAllBoardSlotOccupied() const
{
	auto isOccupied = [](int c) {return c == HorseType::MARK_O || c == HorseType::MARK_X; };
	for (int y = 0; y < _board.size(); ++y)
		if (std::all_of(_board[y].begin(), _board[y].end(), isOccupied) == false)
			return false;
	return true;
}

