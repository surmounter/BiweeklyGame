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

const bool TicTacToeBoard::MarkBoard(const HorseType::value horseType, const BoardCoord & boardCoord)
{
	if (IsEmpty(boardCoord) == false || IsOffBoard(boardCoord))
		return false;
	_board[boardCoord.y][boardCoord.x] = horseType;
	return true;
}

const BoardCoord TicTacToeBoard::ConvertMouseCoordToBoardCoord(const WindowSize & windowSize, const Point & mouseCoord) const
{
	assert(rowCnt > 0 && colCnt > 0, "Error will occur because divide by zero");
	BoardCoord boardCoord;
	boardCoord.x = mouseCoord.GetX() / (windowSize.width / rowCnt);
	boardCoord.y = mouseCoord.GetY() / (windowSize.height / colCnt);
	if (boardCoord.x >= rowCnt) boardCoord.x = rowCnt - 1;
	if (boardCoord.y >= colCnt) boardCoord.y = colCnt - 1;
	return boardCoord;
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

