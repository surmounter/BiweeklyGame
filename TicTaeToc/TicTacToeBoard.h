#pragma once
#include <array>
#include <utility>
#include "WindowSize.h"
#include "Point.h"
#include "HorseType.h"
using Board = std::array<std::array<int, 3>, 3>;
struct BoardSlot 
{
	int x, y;
};

class TicTacToeBoard final
{
public:
	TicTacToeBoard();
	~TicTacToeBoard();

	void ClearBoard();
	const bool PutHorseOnBoard(const HorseType::value horseType, const BoardSlot& boardSlot);
	const BoardSlot ConvertMouseClickPointToBoardSlot(const WindowSize& windowSize, const Point& mouseClickPoint) const;
	void ShowBoard() const;
	const bool CanPutHorse(const BoardSlot& boardSlot) const;
	const HorseType::value IsWin(const BoardSlot &recentPutSlot) const;

private:
	const bool IsEmpty(const BoardSlot& boardSlot) const { return _board[boardSlot.y][boardSlot.x] == HorseType::EMPTY; };
	const bool IsOffBoard(const BoardSlot& boardSlot) const { return (boardSlot.x < 0) || (boardSlot.x >= colCnt) || (boardSlot.y < 0) || (boardSlot.y >= colCnt); };

private:
	const int rowCnt = 3;
	const int colCnt = 3;
	Board _board;
	//int _board[3][3]; // TODO : 상수를 배열 길이로 넣고 싶은데? 되는거 아닌가?
	const BoardSlot adjacentSlots[8] = { {1,-1}, {1,0}, {1,1},
																	{0,-1},			    {0,1},
																	{-1,-1}, {-1,0}, {-1,1} };
};
