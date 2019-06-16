#include "TicTacToeMissionMessageSet.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>

TicTacToeMissionMessageSet::TicTacToeMissionMessageSet()
{
	InitializeMissionMessages(_missionMessageFileDir);
}

TicTacToeMissionMessageSet::~TicTacToeMissionMessageSet()
{
}

void TicTacToeMissionMessageSet::InitializeMissionMessages(const std::string& directory)
{
	_missionMessages.clear();
	SetMissionMessagesFromFile(directory);
	ShuffleMissionMessages();
}

void TicTacToeMissionMessageSet::SetMissionMessagesFromFile(const std::string& directory)
{
	std::ifstream missionMessageFile(directory.data());
	if (missionMessageFile.is_open())
	{
		std::string line;
		while (std::getline(missionMessageFile, line))
			_missionMessages.push_back(line);
		missionMessageFile.close();
	}
}

void TicTacToeMissionMessageSet::ShuffleMissionMessages()
{
	std::random_device rd; // TODO :  ÀÇ¹Ì
	std::mt19937 g(rd());
	std::shuffle(_missionMessages.begin(), _missionMessages.end(), g);
}

void TicTacToeMissionMessageSet::InitializeMissionMessageSet()
{
	InitializeMissionMessages(_missionMessageFileDir);
}

void TicTacToeMissionMessageSet::ShowAllMissionMessages() const
{
	for (auto &missionMessage : _missionMessages)
		std::cout << missionMessage << std::endl;
}

const std::string TicTacToeMissionMessageSet::GetMissionMessage()
{
	const int missionMessageIndex = _getMissionMessageCnt % _missionMessages.size();
	++_getMissionMessageCnt;
	return _missionMessages[missionMessageIndex];
}
