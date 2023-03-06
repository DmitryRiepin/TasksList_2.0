#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include<Windows.h>
#include <conio.h>

enum MenuChoice
{
	MAIN,
	SECOND,
	FILES,
	MAX_SIZE
};

class Menu
{
private:
	int Choice;

	std::vector<std::string> mainMenu = {
		"Create new Task List." ,
		"Open having Task list." ,
		"Exit." };

	std::vector<std::string> secondMenu = {
		"Add task.",
		"Close task.",
		"Print all tasks.",
		"Print all in progress task.",
		"Print all finished task.",
		"<- Back." };

	std::vector<std::string> fileMenu;

public:
	Menu(int choice);
	int menu();
	std::string fileChoice();

private:
	std::vector<std::string> menuChoice();
	void readFilesInDir();

};

