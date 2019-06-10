#pragma once
#include <utility>
#include <SFML/Graphics.hpp>
#define MouseCoord std::pair<int,int>
class TicTacToeController final
{
public:
	TicTacToeController();
	~TicTacToeController();

	void OnStartGameLoop(sf::RenderWindow &window) const;
	void OnClickMouseButton(sf::RenderWindow &window, const MouseCoord mouseCoord) const;
	void OnCloseWindow() const;
};
