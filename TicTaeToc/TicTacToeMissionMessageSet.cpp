#include "TicTacToeMissionMessageSet.h"
#include <iostream>
#include <fstream>

TicTacToeMissionMessageSet::TicTacToeMissionMessageSet()
{
	InitializeMissionMessages(missionMessageFileDir);
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

void TicTacToeMissionMessageSet::ShowAllMissionMessages() const
{
	for (auto &missionMessage : _missionMessages)
		std::cout << missionMessage << std::endl;
}
