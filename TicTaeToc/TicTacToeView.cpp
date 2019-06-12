#include "TicTacToeView.h"
#include <iostream>

TicTacToeView::TicTacToeView()
{
	MapSpriteWithTexture(_boardSprite, _boardTexture, _boardTextureDir);
	MapSpriteWithTexture(_markOSprite, _markOTexture, _markOTextureDir);
	MapSpriteWithTexture(_markXSprite, _markXTexture, _markXTextureDir);
}

TicTacToeView::~TicTacToeView()
{
}

void TicTacToeView::MapSpriteWithTexture(sf::Sprite & sprite, sf::Texture & texture, const std::string &imageDir)
{
	if (texture.loadFromFile(imageDir) == false)
	{
		std::cout << "cannot load texture in " << imageDir << std::endl;
		return;
	}
	sprite.setTexture(texture);
}
