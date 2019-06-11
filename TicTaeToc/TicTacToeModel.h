#pragma once
#include <memory>
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
	void ShowBoard() const;
private:
	std::unique_ptr<TicTacToeBoard> _board;
	std::unique_ptr<TicTacToeMissionMessageSet> _missionMessageSet;
	HorseType::value _turn = HorseType::MARK_O;
};
