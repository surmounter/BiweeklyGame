#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class TicTacToeView final
{
public:
	TicTacToeView();
	~TicTacToeView();

private:
	void MapSpriteWithTexture(sf::Sprite &sprite, sf::Texture &texture, const std::string &imageDir);
private:
	const std::string _boardTextureDir = "Resource/board.png";
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;
	const std::string _markOTextureDir = "Resource/markO.png";
	sf::Texture _markOTexture;
	sf::Sprite _markOSprite;
	const std::string _markXTextureDir = "Resource/markX.png";
	sf::Texture _markXTexture;
	sf::Sprite _markXSprite;
};
