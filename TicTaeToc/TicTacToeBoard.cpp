#include "TicTacToeBoard.h"
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

const bool TicTacToeBoard::PutHorseOnBoard(const HorseType::value horseType, const BoardSlot & boardSlot)
{
	if (IsPutHorse(boardSlot) == false)
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

const bool TicTacToeBoard::IsPutHorse(const BoardSlot & boardSlot) const
{
	if (IsEmpty(boardSlot) == false || IsOffBoard(boardSlot))
		return false;
	return true;
}

const HorseType::value TicTacToeBoard::IsWin(const BoardSlot &recentPutSlot) const
{
	int sameHorseCntInRow = 1;
	for (auto adjacentSlot : adjacentSlots)
		if (IsOffBoard(adjacentSlot) == false && _board[recentPutSlot.y][recentPutSlot.x] == _board[adjacentSlot.y][adjacentSlot.x])
			++sameHorseCntInRow;
	if (sameHorseCntInRow == 3)
		return static_cast<HorseType::value>(_board[recentPutSlot.y][recentPutSlot.x]);
}

