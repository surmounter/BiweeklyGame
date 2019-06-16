#include "TicTacToeAudioMgr.h"

TicTacToeAudioMgr::TicTacToeAudioMgr()
{
	_bgm.openFromFile(_bgmDir);
	_bgm.setLoop(true);
	_bgm.play();
}

TicTacToeAudioMgr::~TicTacToeAudioMgr()
{
}
