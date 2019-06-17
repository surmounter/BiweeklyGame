#include "TicTacToeGate.h"
#include <iostream>
int main()
{	
	WindowSize windowSize = std::make_pair(600, 600);
	TicTacToeGate gate(windowSize);
	gate.UpdateGameLoop();
	return 0;	
}
