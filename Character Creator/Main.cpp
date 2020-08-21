#include "Character.h"
#include "Constants.h"
#include <windows.h>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

void Format(int windowWidth, int windowHeight, int fontSize);
void Intro();
void Outro();

int main()
{
	Format(WINDOW_WIDTH, WINDOW_HEIGHT, FONT_SIZE);

	Intro();
	system("cls");

	Character character;

	character.SetName();
	system("cls");
	character.SetCharacterJob();
	system("cls");
	std::cout << "Rolling Stats...\n";
	Sleep(1000);
	character.RollStats();
	std::cout << "Stats Rolled!\n";
	Sleep(1000);
	system("cls");
	character.SetStats();
	character.DisplayCharacter();
	system("pause");

	Outro();
	return 0;
}

void Format(int windowWidth, int windowHeight, int fontSize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   //Width of each character in the font
	cfi.dwFontSize.Y = fontSize;            //Height of each character in the font
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); //Set Font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, windowWidth, windowHeight, TRUE);
}

void Intro()
{
	std::cout << "Welcome to VOID-RPG Character Creator 2.0\n";
	Sleep(2000);
	std::cout << "You will be creating a character by: \n";
	Sleep(2000);
	std::cout << "-Choosing their name.\n";
	Sleep(2000);
	std::cout << "-Choosing their job.\n";
	Sleep(2000);
	std::cout << "-Rolling a d20 to determine their available stat values.\n";
	Sleep(2000);
	std::cout << "-Assigning those values to their stats.\n";
	Sleep(1000);
	system("pause");
}

void Outro()
{
	std::cout << "Thank you for playing VOID-RPG Character Creator 2.0!\n";
	Sleep(1000);
	std::cout << "Have a nice day!\n";
	Sleep(1000);
}
