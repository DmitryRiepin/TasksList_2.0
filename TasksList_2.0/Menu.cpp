#include "Menu.h"

using namespace std;
using namespace filesystem;


Menu::Menu(int choice)
{
	if (choice == FILES)
	{
		readFilesInDir();
	}
	Choice = choice;	
}


int Menu::menu()
{
	int choose = 0;

	std::vector<std::string> menu = menuChoice();

	std::string flagInput = "\033[3;100;30m";
	std::string resetFlag = "\033[0m";

	while (true)
	{
		system("cls");
		std::cout << "\t Please choose an action: \n";
		for (int i = 0; i < menu.size(); ++i)
		{
			if (i == choose)
			{
				std::cout << flagInput << menu[i] << resetFlag << std::endl;
			}
			else
			{
				std::cout << menu[i] << std::endl;
			}
		}

		int keybordKey = _getwch();

		switch (keybordKey)
		{
		case 13: // ENTER
		{
			system("cls");
			return choose + 1;

		}
		case 72: { // UP
			if (choose <= 0)
			{
				choose = 0;
			}
			else { choose--; }
			continue;
		}
		case 80: // DOWN
		{
			if (choose > menu.size() - 2)
			{
				choose = menu.size() - 1;
			}
			else { choose++; }
			continue;
		}
		}
	}
}

std::string Menu::fileChoice()
{
	std::string fullName = fileMenu[menu() - 1];
	std::string shortName;

	for (int i = 0; i < fullName.size(); ++i)
	{
		char ch = fullName[i];
		if (ch == '.')
		{
			return shortName;
		}
		else
		{
			shortName += ch;
			continue;
		}
	}
}

std::vector<std::string> Menu::menuChoice()
{
	if (Choice == MAIN) return mainMenu;
	else if (Choice == SECOND) return secondMenu;
	else if (Choice == FILES) return fileMenu;
}

void Menu::readFilesInDir()
{
	path p("Tasks");
	for (auto i = directory_iterator(p); i != directory_iterator(); i++)
	{
		if (!is_directory(i->path())) // we eliminate directories in a list
		{
			fileMenu.push_back(i->path().filename().string());
		}
		else
			continue;
	}
}
