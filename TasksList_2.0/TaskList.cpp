#include <iostream>
#include "TaskList.h"


TaskList::TaskList()
{
}

TaskList::TaskList(std::string openFileName)
{
	fileName = openFileName;
	readFile();
}

TaskList::~TaskList()
{
	saveTaskList();
}

void TaskList::addTask()
{
	TaskString task;
	task.createTask();

	int tuskNum = taskLists.size() + 1;
	task.setTaskNum(tuskNum);

	taskLists.push_back(task);
}

void TaskList::finishTask()
{
	int taskNum;
	printProgressTask();
	std::cout << "\n\tInput closing Task #: ";
	std::cin >> taskNum;
	if (std::cin.fail() || taskNum <= 0 || taskNum > taskLists.size())
	{
		std::cout << "\n Incorrect input!\n Try againe!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		finishTask();
	}

	for (auto& task : taskLists)
	{
		if (taskNum == task.getTaskNum())
			task.closeTask();
		std::cout << std::endl;
	}
}

const void TaskList::printAll()
{
	for (auto& task : taskLists)
	{
		task.printTask();
		std::cout << std::endl;
	}
}

const void TaskList::printProgressTask()
{
	for (auto& task : taskLists)
	{
		if (!task.getIsFinished())
		{
			task.printTask();
			std::cout << std::endl;
		}
	}
}

const void TaskList::printFinishedTask()
{
	for (auto& task : taskLists)
	{
		if (task.getIsFinished())
		{
			task.printTask();
			std::cout << std::endl;
		}
	}
}

void TaskList::saveTaskList()
{
	std::ofstream save;
	if (fileName.empty())
	{
		std::cout << "Plise input file name!" << std::endl;
		std::getline(std::cin, fileName);
	}
	save.open("Tasks\\" + fileName + ".csv", std::ofstream::trunc);

	if (!save)
	{
		std::cout << "\x1B[31mSorry file not create\033[0m\n";
	}

	save << "Name;" << "Position;" << "Task;" << "Start task data;" << "Finish task data\n";

	for (int i = 0; i < taskLists.size(); ++i)
	{
		std::string finishTimePrint = taskLists[i].getIsFinished() == true ?
			taskLists[i].dataString(taskLists[i].getEndData()) : "In progress!";

		save << taskLists[i].getName() << ';' << taskLists[i].getPosition() << ';' << taskLists[i].getTask() << ";"
			<< taskLists[i].dataString(taskLists[i].getStartData()) << ";"
			<< finishTimePrint << std::endl;
	}
	save.close();
}

void TaskList::readFile()
{
	std::ifstream read;

	read.open("Tasks\\" + fileName + ".csv");
	if (!read)
	{
		std::cout << "\x1B[31mSorry file not found!\033[0m\n";
	}

	int countReaad = 0;
	while (!read.eof())
	{
		TaskString task;
		std::string readString;
		std::getline(read, readString);

		if (countReaad == 0 || readString == "")
		{
			countReaad++;
			continue;
		}

		int count = 0;
		char separator = ';';
		std::string readOne;

		for (int i = 0; i <= readString.size(); ++i)
		{
			char ch = readString[i];
			if (ch == separator && count == 0)
			{
				task.setName(readOne);
				readOne = "";
				count++;
			}
			else if (ch == separator && count == 1)
			{
				task.setPosition(readOne);
				readOne = "";
				count++;
			}
			else if (ch == separator && count == 2)
			{
				task.setTask(readOne);
				readOne = "";
				count++;
			}
			else if (ch == separator && count == 3)
			{
				task.readData(readOne, "startData");
				readOne = "";
				count++;
			}
			else if (ch == '\0')
			{
				task.readData(readOne, "endData");
				readOne = "";
				count++;
			}

			if (ch != separator)
			{
				readOne += ch;
			}
		}
		task.setTaskNum(countReaad);
		++countReaad;
		taskLists.push_back(task);
	}
	read.close();
}





