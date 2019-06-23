#include "SpriteManager.h"
#include <iostream>
SpriteManger::SpriteManger(const std::string & textureDir, const int spriteCnt)
{
	if (_texture.loadFromFile(textureDir) == false)
	{
		std::cout << "cannot load texture in " << textureDir << std::endl;
		return;
	}

	for (int i = 0; i < spriteCnt; ++i)
	{
		sf::Sprite sprite;
		sprite.setTexture(_texture);
		_sprites.push_back(sprite);
	}
}

SpriteManger::~SpriteManger()
{
}

const bool SpriteManger::DrawSprite(sf::RenderWindow &window, const Point & pos)
{
	if (curSpritePos >= _sprites.size())
		return false;
	_sprites[curSpritePos].setPosition(pos.GetX(), pos.GetY());
	window.draw(_sprites[curSpritePos]);
	++curSpritePos;
	return true;
}
