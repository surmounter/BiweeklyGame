#pragma once
#include <SFML/Audio.hpp>
#include <string>
class TicTacToeAudio final
{
public:
	TicTacToeAudio(const std::string audioDir);
	~TicTacToeAudio();

	void Play();

private:
	sf::SoundBuffer _audioBuffer;
	sf::Sound _audio;
};
