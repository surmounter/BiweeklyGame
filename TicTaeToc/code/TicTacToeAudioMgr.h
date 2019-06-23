#pragma once
#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>
#include "TicTacToeAudioKind.h"
class TicTacToeAudio;
class TicTacToeAudioMgr final
{
public:
	TicTacToeAudioMgr();
	~TicTacToeAudioMgr();

	void Play(const TicTacToeAudioKind::Value audioKind);

private:
	const char* _bgmDir = "Resource/tictactoeBGM.WAV";
	sf::Music _bgm;

	std::unordered_map<TicTacToeAudioKind::Value, std::unique_ptr<TicTacToeAudio>> _audios;
	const char* _putHorseSoundDir = "Resource/putHorseSound.wav";

};