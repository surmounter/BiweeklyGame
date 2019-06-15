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

	for (int y = 0; y < rowCnt; ++y)
	{	
		int x = 0;
		for (; x < colCnt; ++x)
			if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[y][0])
				break;
		const bool isSameInYRow = (x == colCnt);
		if (isSameInYRow) return static_cast<TicTacToeGameResult::Value>(_board[y][0]);
	}

	for (int x = 0; x < colCnt; ++x)
	{
		int y = 0;
		for (; y < rowCnt; ++y)
			if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[0][x])
				break;
		const bool isSameInXCol = (y == rowCnt);
		if (isSameInXCol) return static_cast<TicTacToeGameResult::Value>(_board[0][x]);
	}

	int i = 0;
	for (; i < _board.size(); ++i)
	{
		if (_board[i][i] == HorseType::EMPTY || _board[i][i] != _board[0][0])
			break;
	}
	const bool isSameInDiagonal = (i == _board.size());
	if (isSameInDiagonal) return static_cast<TicTacToeGameResult::Value>(_board[0][0]);

	int y = 0;
	int x = colCnt - 1;
	for (; x >= 0 && y < rowCnt; --x, ++y)
		if (_board[y][x] == HorseType::EMPTY || _board[y][x] != _board[0][colCnt - 1])
			break;
	const bool isSameInAntiDiagonal = (x == -1 && y == rowCnt);
	if (isSameInAntiDiagonal) return static_cast<TicTacToeGameResult::Value>(_board[0][colCnt - 1]);

	// TODO: draw가 아니라 새로운 속성 추가해서 none 수정해야한다.
	return TicTacToeGameResult::DRAW;
}

const HorseType::value TicTacToeBoard::CheckIfHorsesAreSameInARow(const int row) const
{
	assert(row < _board.size() && row >= 0, "out of bound in row");
	assert(_board.size() > 0 && _board[0].size() > 0, "_board is empty");
	for (int x = 0; x < _board[row].size(); ++x)
		if (_board[row][x] == HorseType::EMPTY || _board[row][0] != _board[row][x])
			return HorseType::EMPTY;
	return static_cast<HorseType::value>(_board[row][0]);
}

const HorseType::value TicTacToeBoard::CheckIfHorsesAreSameInAColume(const int col) const
{
	assert(col < _board.size() && col >= 0, "out of bound in col");
	assert(_board.size() > 0 && _board[0].size() > 0, "_board is empty");
	for (int y = 0; y < _board.size(); ++y)
		if (_board[y][col] == HorseType::EMPTY || _board[0][col] != _board[y][col])
			return HorseType::EMPTY;
	return static_cast<HorseType::value>(_board[0][col]);	
}

const HorseType::value TicTacToeBoard::ChckeIfHorseInADiagonal(const DiagonalDirection::Value direction) const
{
	assert(_board.size() > 0 && _board[0].size() > 0, "_board is empty");
	switch (direction)
	{
	case DiagonalDirection::LEFTTOP_RIGHTDOWN:
		for (int i = 0; i < _board.size(); ++i)
			if (_board[i][i] == HorseType::EMPTY || _board[0][0] != _board[i][i])
				return HorseType::EMPTY;
		return static_cast<HorseType::value>(_board[0][0]);
		break;
	case DiagonalDirection::RIGHTTOP_LEFTDOWN:
		for(int i = _board.size() - 1; i >= 0; --i)
			if (_board[i][i] == HorseType::EMPTY || _board[_board.size()-1][_board.size()-1] != _board[i][i])
				return HorseType::EMPTY;
		return static_cast<HorseType::value>(_board[_board.size()-1][_board.size()-1]);
		break;
	default:
		break;
	}
}

