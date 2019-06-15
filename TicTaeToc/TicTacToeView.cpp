#include "TicTacToeView.h"
#include <iostream>
TicTacToeView::TicTacToeView(const int boardSlotCnt)
{
	_boardSprite = std::make_unique<SpriteManger>(_boardTextureDir, 1);
	_markOSprite = std::make_unique<SpriteManger>(_markOTextureDir, boardSlotCnt);
	_markXSprite = std::make_unique<SpriteManger>(_markXTextureDir, boardSlotCnt);
}

TicTacToeView::~TicTacToeView()
{
}

void TicTacToeView::UpdateBoard(const std::array<std::array<int, 3>, 3>& board, sf::RenderWindow & window) const
{	
	window.clear();
	InitializeSprites();
	_boardSprite->DrawSprite(window, { 0.0f,0.0f } /*board sprite pos*/);
		
	for (int y = 0; y < board.size(); ++y)
	{
		int rowCnt = board.size();
		for (int x = 0; x < board[y].size(); ++x)
		{
			int colCnt = board[y].size();
			const float spritePosX = (window.getSize().x / colCnt) * x;
			const float spritePosY = (window.getSize().y / rowCnt) * y;
			const Point spritePos = { spritePosX, spritePosY };
			auto horseType = static_cast<const HorseType::value>(board[y][x]);
			DrawHorse(window, horseType, spritePos);
		}
	}
	window.display();	
}

void TicTacToeView::InitializeSprites() const
{
	_boardSprite->Initialize();
	_markOSprite->Initialize();
	_markXSprite->Initialize();
}

void TicTacToeView::DrawHorse(sf::RenderWindow & window, const HorseType::value horseType, const Point &pos) const
{
	switch (horseType)
	{
	case HorseType::MARK_O:
		_markOSprite->DrawSprite(window, pos);
		break;
	case HorseType::MARK_X:
		_markXSprite->DrawSprite(window, pos);
		break;
	default:
		break;
	}
}
