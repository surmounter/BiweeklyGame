#include "TicTacToeAudioMgr.h"
#include "TicTacToeAudio.h"
TicTacToeAudioMgr::TicTacToeAudioMgr()
{
	_bgm.openFromFile(_bgmDir);
	_bgm.setLoop(true);
	_bgm.play();

	_audios[TicTacToeAudioKind::PUTHORSE] = std::make_unique<TicTacToeAudio>(_putHorseSoundDir);
}

TicTacToeAudioMgr::~TicTacToeAudioMgr()
{
}

void TicTacToeAudioMgr::Play(const TicTacToeAudioKind::Value audioKind)
{
	_audios[audioKind]->Play();
}
