#include "TicTacToeView.h"
#include <iostream>
TicTacToeView::TicTacToeView(const int boardSlotCnt)
{
	_boardSprite = std::make_unique<SpriteManger>(_boardTextureDir, 1);
	_markOSprite = std::make_unique<SpriteManger>(_markOSprite, boardSlotCnt);
	_markXSprite = std::make_unique<SpriteManger>(_markXSprite, boardSlotCnt);
}

TicTacToeView::~TicTacToeView()
{
}

void TicTacToeView::UpdateBoard(const std::array<std::array<int, 3>, 3>& board, sf::RenderWindow & window) const
{
	for (int y = 0; y < board.size(); ++y)
	{
		for (int x = 0; x < board[y].size(); ++x)
		{
			switch (board[y][x])
			{
			case HorseType::MARK_O:
				break;
			case HorseType::MARK_X:
				break;
			default:
				break;
			}
		}
	}


}
