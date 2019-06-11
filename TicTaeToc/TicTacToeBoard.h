#pragma once

#include <utility>
#include "WindowSize.h"
#include "Point.h"

struct BoardCoord 
{
	int x, y;
};

struct HorseType
{
	enum value {EMPTY = 0, MARK_O, MARK_X, NUM_OF_HORSE_TYPE};
};

class TicTacToeBoard final
{
public:
	TicTacToeBoard();
	~TicTacToeBoard();

	void ClearBoard()
	{ 
		memset(_board, HorseType::EMPTY, sizeof(_board)); 
	}
	const bool MarkBoard(const HorseType::value horseType, const BoardCoord& boardCoord);
	const BoardCoord ConvertMouseCoordToBoardCoord(const WindowSize& windowSize, const Point& mouseCoord) const;
	void ShowBoard() const;

private:
	const bool IsEmpty(const BoardCoord& boardCoord) const
	{
		return _board[boardCoord.y][boardCoord.x] == HorseType::EMPTY; 
	};

	const bool IsOffBoard(const BoardCoord& boardCoord) const 
	{
		return (boardCoord.x < 0) || (boardCoord.x >= colCnt) || (boardCoord.y < 0) || (boardCoord.y >= colCnt);
	};
private:
	const int rowCnt = 3;
	const int colCnt = 3;
	int _board[3][3]; // TODO : 상수를 배열 길이로 넣고 싶은데? 되는거 아닌가?
};
