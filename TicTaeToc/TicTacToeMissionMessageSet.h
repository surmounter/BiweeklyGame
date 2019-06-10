#pragma once
#include <string>
#include <vector>

class TicTacToeMissionMessageSet final
{
public:
	TicTacToeMissionMessageSet();
	~TicTacToeMissionMessageSet();

	void ShowAllMissionMessages() const;

private:
	void InitializeMissionMessages(const std::string directory);	
private:
	const std::string missionMessageFileDir = "Resource/missionMessageFile.txt";
	std::vector<std::string> _missionMessages;
};