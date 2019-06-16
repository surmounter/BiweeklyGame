#include "TicTacToeAudio.h"

TicTacToeAudio::TicTacToeAudio(const std::string audioDir)
{
	_audioBuffer.loadFromFile(audioDir);
	_audio.setBuffer(_audioBuffer);
}

TicTacToeAudio::~TicTacToeAudio()
{
}

void TicTacToeAudio::Play() 
{
	_audio.play();
}
