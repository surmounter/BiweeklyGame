#include "TicTacToeBoard.h"
#include <string.h>

TicTacToeBoard::TicTacToeBoard()
{
}

TicTacToeBoard::~TicTacToeBoard()
{
}

const bool TicTacToeBoard::MarkBoard(const HorseType::value horseType, const BoardCoord & boardCoord)
{
	if (IsEmpty(boardCoord) == false || IsOffBoard(boardCoord) == false)
		return false;
	_board[boardCoord.y][boardCoord.x] = horseType;
	return true;
}

