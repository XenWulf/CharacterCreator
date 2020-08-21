#include "Character.h"
#include "Constants.h"
#include <random>
#include <windows.h>

using namespace std;

Character::Character() :
	m_Name("Unnamed"),
	m_Job("Unemployed"),
	m_HP(0),
	m_Charisma(0),
	m_Stamina(0),
	m_Strength(0),
	m_Wisdom(0),
	m_Dexterity(0),
	m_Intelligence(0)
{
}

Character::~Character()
{
}

void Character::SetName()
{
	string name;
	cout << "What would you like their name to be?\n";
	cin >> name;
	cout << "Your character's name is now: " << name << "\n";
	m_Name = name;
	Sleep(1500);
}

std::string Character::GetName()
{
	return m_Name;
}

void Character::SetCharacterJob()
{
	string job;
	cout << "What would you like their job to be?\n";
	cin >> job;
	cout << "Your character's job is now: " << job << "\n";
	m_Job = job;
	Sleep(1500);
}

std::string Character::GetCharacterJob()
{
	return m_Job;
}

void Character::SetStats()
{
	bool setting = true;
	while (setting)
	{
		int stat;

		int amount;

		DisplayStats();
		DisplayRolls();

		cout << "Which Stat would you like to modify? (1 - 7)\nInput: ";

		cin >> stat;
		if (stat > STATS || stat <= 0)
		{
			cout << "\nPlease enter a valid integer.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nWhich roll would you like to set it to? (1 - 7)\nInput: ";
			cin >> amount;

			if (amount > m_Rolls.size() || amount <= 0)
			{
				cout << "\nPlease enter a valid integer.\n";
				Sleep(1500);
			}
			else
			{
				SetStat(stat, amount);
			}
		}
		system("cls");
		if (m_Rolls.size() == 0)
		{
			setting = false;
			system("cls");
		}
	}
}

void Character::SetStat(int stat, int amount)
{
	if (stat == 1)
	{
		if (m_HP >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: HP to " << m_Rolls[amount - 1];
			m_HP = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 2)
	{
		if (m_Stamina >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Stamina to " << m_Rolls[amount - 1];
			m_Stamina = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 3)
	{
		if (m_Strength >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Strength to " << m_Rolls[amount - 1];
			m_Strength = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 4)
	{
		if (m_Intelligence >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Intelligence to " << m_Rolls[amount - 1];
			m_Intelligence = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 5)
	{
		if (m_Dexterity >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Dexterity to " << m_Rolls[amount - 1];
			m_Dexterity = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 6)
	{
		if (m_Wisdom >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Wisdom to " << m_Rolls[amount - 1];
			m_Wisdom = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
	if (stat == 7)
	{
		if (m_Charisma >= 1)
		{
			cout << "\nCannot modify a stat that has been previously modified.\n";
			Sleep(1500);
		}
		else
		{
			cout << "\nModifying: Charisma to " << m_Rolls[amount - 1];
			m_Charisma = m_Rolls[amount - 1];
			RemoveElement(amount - 1);
			Sleep(1500);
		}
	}
}

void Character::DisplayStats()
{
	cout << "1. HP: " << m_HP << "\n" << "2. Stamina: " << m_Stamina << "\n" << "3. Strength: " << m_Strength << "\n" <<
		"4. Intelligence: " << m_Intelligence << "\n" << "5. Dexterity: " << m_Dexterity << "\n" <<
		"6. Wisdom: " << m_Wisdom << "\n" << "7. Charisma: " << m_Charisma << "\n";
}

void Character::RollStats()
{
	for (int i = 0; i < STATS; i++)
	{
		int stat = RandomInt(STATMIN, STATMAX);
		m_Rolls.push_back(stat);
	}
}

void Character::DisplayRolls()
{
	cout << "Your rolls are: \n";
	for (int i = 0; i < m_Rolls.size(); i++)
	{
		cout << i + 1 << ": " << m_Rolls[i];
		if(i != m_Rolls.size() - 1)
		{
			cout << "\t";
		}
		else
		{
			cout << "\n";
		}
	}
}

void Character::DisplayCharacter()
{
	cout << "Name: " << m_Name << "\n";
	cout << "Job: " << m_Job << "\n";
	DisplayStats();
}

void Character::RemoveElement(int element)
{
	int indexA = element;
	int indexB = m_Rolls.size() - 1;

	int tempElementA = m_Rolls.at(indexA);
	int tempElementB = m_Rolls.at(indexB);

	m_Rolls.at(indexA) = tempElementB;
	m_Rolls.at(indexB) = tempElementA;
	m_Rolls.pop_back();
}

int Character::RandomInt(int min, int max)
{
	random_device seed;
	mt19937 mersenneTwister(seed());

	uniform_int_distribution<int> distribution(min, max);
	return distribution(mersenneTwister);
}
