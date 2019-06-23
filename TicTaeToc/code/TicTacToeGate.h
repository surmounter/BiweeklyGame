#pragma once
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#define WindowSize std::pair<int,int>

class TicTacToeController;

class TicTacToeGate final
{

public:
	TicTacToeGate(const WindowSize windowSize);
	~TicTacToeGate();
	void UpdateGameLoop();
private:
	sf::RenderWindow _window;
	const std::string _gameTitle = "TicTacToe";
	std::unique_ptr<TicTacToeController> _controller;
};
