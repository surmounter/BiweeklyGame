#pragma once
#include <memory>
class TicTacToeBoard;
class TicTacToeMissionMessageSet;

class TicTacToeModel final
{
public:
	TicTacToeModel();
	~TicTacToeModel();

private:
	std::unique_ptr<TicTacToeBoard> _board;
	std::unique_ptr<TicTacToeMissionMessageSet> _missionMessageSet;
};