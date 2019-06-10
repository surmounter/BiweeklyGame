#pragma once
#include <string>
#include <vector>

class TicTacToeMissionMessageSet final
{
public:
	TicTacToeMissionMessageSet();
	~TicTacToeMissionMessageSet();

private:
	void InitializeMissionMessages(const std::string directory);
private:
	const std::string missionMessageFileDir = "Resources/missionMessageFile.txt";
	std::vector<std::string> _missionMessages;
};