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

const HorseType::value TicTacToeBoard::IsWin(const BoardSlot &recentPutSlot) const
{



	return HorseType::EMPTY;
}

const HorseType::value TicTacToeBoard::CheckIfHorseInARow(const int row) const
{
	assert(row < _board.size() && row >= 0, "out of bound in row");

	int firstHorseInARow = _board[row][0];
	if (firstHorseInARow == HorseType::EMPTY)
		return HorseType::EMPTY;

	auto isSameWithFirstHorseInARow = [firstHorseInARow](int horse) { return horse == firstHorseInARow; };
	if (std::all_of(_board[row].begin(), _board[row].end(), isSameWithFirstHorseInARow))
		return static_cast<HorseType::value>(firstHorseInARow);
	return HorseType::EMPTY;
}

const HorseType::value TicTacToeBoard::CheckIfHorseInAColume(const int col) const
{
	assert(col < _board && col >= 0 )
}

