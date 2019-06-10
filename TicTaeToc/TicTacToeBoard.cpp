#include "TicTacToeBoard.h"
#include <string.h>
#include <iostream>

TicTacToeBoard::TicTacToeBoard()
{
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

void TicTacToeBoard::ShowBoard() const
{
	for (int y = 0; y < rowCnt; ++y)
	{
		for (int x = 0; x < colCnt; ++x)
			std::cout << _board[y][x] << " ";
		std::cout << std::endl;
	}
}

