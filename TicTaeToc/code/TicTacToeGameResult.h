#pragma once
#include "HorseType.h"
struct TicTacToeGameResult 
{
	enum Value {WINNER_MARK_O = HorseType::MARK_O, 
							WINNER_MARK_X = HorseType::MARK_X, 
							DRAW,
							NONE, };
};
