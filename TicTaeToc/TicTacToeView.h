#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class TicTacToeView final
{
public:
	TicTacToeView();
	~TicTacToeView();

private:

private:
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;
	sf::Texture _markOTexture;
	sf::Sprite _markOSprite;
	sf::Texture _markXTexture;
	sf::Sprite _markXSprite;
};
