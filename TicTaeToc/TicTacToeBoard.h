#pragma once

struct HorseType
{
	enum {MARK_O = 0, MARK_X, NUM_OF_HORSE_TYPE};
};

class TicTacToeBoard final
{
public:
	TicTacToeBoard();
	~TicTacToeBoard();

	void InitializeBoard();
private:
	int _board[3][3];
};
