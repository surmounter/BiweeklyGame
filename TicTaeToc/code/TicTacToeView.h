#pragma once
#include <array>
#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "HorseType.h"
#include "SpriteManager.h"

class TicTacToeView final
{
public:
	TicTacToeView(const int boardSlotCnt);
	~TicTacToeView();

	void UpdateBoard(const std::array<std::array<int, 3>, 3>& board, sf::RenderWindow &window) const;

private:
	void InitializeSprites() const;
	void DrawBoard(sf::RenderWindow &window) const;
	void DrawHorsesOnBoard(sf::RenderWindow &window, const std::array<std::array<int, 3>, 3>& board) const;
	void DrawHorse(sf::RenderWindow &window, const HorseType::value horseType, const Point &pos) const;

private:
	const std::string _boardTextureDir = "Resource/board.png";
	const std::string _markOTextureDir = "Resource/markO.png";
	const std::string _markXTextureDir = "Resource/markX.png";

	std::unique_ptr<SpriteManger> _boardSprite;
	std::unique_ptr<SpriteManger> _markOSprite;
	std::unique_ptr<SpriteManger> _markXSprite;

};
