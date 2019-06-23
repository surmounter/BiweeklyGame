#pragma once
#include <string>
#include <vector>

class TicTacToeMissionMessageSet final
{
public:
	TicTacToeMissionMessageSet();
	~TicTacToeMissionMessageSet();

	void InitializeMissionMessageSet();
	void ShowAllMissionMessages() const;
	const std::string GetMissionMessage();

private:
	void InitializeMissionMessages(const std::string& directory);	
	void SetMissionMessagesFromFile(const std::string& directory);
	void ShuffleMissionMessages();

private:
	const std::string _missionMessageFileDir = "Resource/missionMessageFile.txt";
	std::vector<std::string> _missionMessages;
	int _getMissionMessageCnt = 0;
};