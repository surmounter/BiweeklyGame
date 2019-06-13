#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Point.h"

class SpriteManger final
{
public:
	SpriteManger(const std::string &textureDir, const int spriteCnt);
	~SpriteManger();

	void Initialize() { curSpritePos = 0; };
	const bool DrawSprite(sf::RenderWindow &window, const Point &pos);

private:
	sf::Texture _texture;
	std::vector<sf::Sprite> _sprites;
	int curSpritePos = 0;
};
