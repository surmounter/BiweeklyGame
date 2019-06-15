#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "HorseType.h"
#include "TicTacToeGameResult.h"
#include "Point.h"
using Board = std::array<std::array<int, 3>, 3>;
class TicTacToeBoard;
class TicTacToeMissionMessageSet;

class TicTacToeModel final
{
public:
	TicTacToeModel();
	~TicTacToeModel();
	
	const bool PutHorse(const Point& mouseClickPoint, const sf::RenderWindow &window);
	void ChangeTurn() { _turn = (_turn == HorseType::MARK_O) ? HorseType::MARK_X : HorseType::MARK_O; };
	void ShowResultOfTurn() const;
	const int GetBoardSlotCnt() const;
	const Board GetBoard() const;
	const TicTacToeGameResult::Value GetGameResult() const;

private:
	const bool TryMission() const;

private:
	std::unique_ptr<TicTacToeBoard> _board;
	std::unique_ptr<TicTacToeMissionMessageSet> _missionMessageSet;
	HorseType::value _turn = HorseType::MARK_O;
	const char* _missionMessageTitle = "Mission Message. Click ok buttion if you clear mission or not your turn will be taken over";
};
