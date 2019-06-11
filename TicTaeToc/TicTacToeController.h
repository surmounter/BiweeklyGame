#pragma once
#include <utility>
#include <SFML/Graphics.hpp>
#include "Point.h"
class TicTacToeController final
{
public:
	TicTacToeController();
	~TicTacToeController();

	void OnStartGameLoop(sf::RenderWindow &window) const;
	void OnClickMouseButton(sf::RenderWindow &window, const Point& mouseClickPoint) const;
	void OnCloseWindow() const;
};
