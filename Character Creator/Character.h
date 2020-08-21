#pragma once
#include <iostream>
#include <vector>
class Character
{
public:
	Character();
	~Character();

	void SetName();
	std::string GetName();

	void SetCharacterJob();
	std::string GetCharacterJob();

	void SetStats();
	void SetStat(int stat, int amount);
	void DisplayStats();
	void RollStats();
	void DisplayRolls();

	void DisplayCharacter();

	void RemoveElement(int element);

	int RandomInt(int min, int max);

private:
	std::string m_Name;
	std::string m_Job;

	int m_HP;
	int m_Stamina;
	int m_Intelligence;
	int m_Strength;
	int m_Dexterity;
	int m_Wisdom;
	int m_Charisma;

	std::vector<int> m_Rolls;
};

