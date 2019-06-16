#pragma once
#include <SFML/Audio.hpp>

class TicTacToeAudioMgr final
{
public:
	TicTacToeAudioMgr();
	~TicTacToeAudioMgr();

private:
	const char* _bgmDir = "Resource/tictactoeBGM.WAV";
	sf::Music _bgm;
};