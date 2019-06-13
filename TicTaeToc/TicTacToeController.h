#pragma once
#include <utility>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Point.h"

class TicTacToeModel;
class TicTacToeView;
class TicTacToeController final
{
public:
	TicTacToeController();
	~TicTacToeController();

	void OnStartGameLoop(sf::RenderWindow &window) const;
	void OnClickMouseButton(sf::RenderWindow &window, const Point& mouseClickPoint) const;
	void OnCloseWindow() const;

private:
	std::unique_ptr<TicTacToeModel> _model;
	std::unique_ptr<TicTacToeView> _view;
};
