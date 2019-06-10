#include "TicTacToeMissionMessageSet.h"
#include <fstream>

TicTacToeMissionMessageSet::TicTacToeMissionMessageSet()
{
}

TicTacToeMissionMessageSet::~TicTacToeMissionMessageSet()
{
}

void TicTacToeMissionMessageSet::InitializeMissionMessages(const std::string directory)
{
	_missionMessages.clear();
	std::ifstream missionMessageFile(directory.data());
	if (missionMessageFile.is_open())
	{
		std::string line;
		while (std::getline(missionMessageFile, line))
			_missionMessages.push_back(line);
		missionMessageFile.close();
	}
}
