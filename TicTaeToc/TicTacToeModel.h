#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "HorseType.h"
#include "Point.h"

class TicTacToeBoard;
class TicTacToeMissionMessageSet;

class TicTacToeModel final
{
public:
	TicTacToeModel();
	~TicTacToeModel();
	
	const bool PutHorse(const Point& mouseClickPoint, const sf::RenderWindow &window);
	void ChangeTurn() { _turn = (_turn == HorseType::MARK_O) ? HorseType::MARK_X : HorseType::MARK_O; };
	void ShowBoard() const;

private:
	std::unique_ptr<TicTacToeBoard> _board;
	std::unique_ptr<TicTacToeMissionMessageSet> _missionMessageSet;
	HorseType::value _turn = HorseType::MARK_O;
	const char* _missionMessageTitle = "Mission Message. Click ok buttion if you clear mission or not your turn will be taken over";
};
