#include <iostream>
#include <iomanip>
#include "TaskString.h"

void TaskString::createTask()
{
	std::cout << "Input new task (maximum of characters 400): " << std::endl;
	std::string inputTask;
	checkInputString(inputTask, "task");
	setTask(inputTask);

	std::cout << "Input name task maker(maximum of characters 50): " << std::endl;
	std::string inputName;
	checkInputString(inputName, "name");
	setName(inputName);

	std::cout << "Input position task maker(maximum of characters 50): " << std::endl;
	std::string inputPosition;
	checkInputString(inputPosition, "position");
	setPosition(inputPosition);

	int day, mounth, year;
	std::cout << "Input start data: " << std::endl;
	checkInputData(day, mounth, year);
	setStartData(day, mounth, year);

	isFinished = false;
}

void TaskString::closeTask()
{
	int day, mounth, year;
	std::cout << "Input finished data: " << std::endl;
	checkInputData(day, mounth, year);
	setEndData(day, mounth, year);

	isFinished = true;
}

std::string TaskString::dataString(const Data& data)
{
	std::string day = std::to_string(data.Day);
	std::string mounth = std::to_string(data.Mounth);
	std::string year = std::to_string(data.Year);

	return day + '/' + mounth + '/' + year;
}

void TaskString::linePrint(std::string start, std::string middle, std::string cross, std::string end, int count, int len) {
	std::cout << start;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < len; j++) std::cout << middle;
		std::cout << cross;
	}
	for (int j = 0; j < len; j++) std::cout << middle;
	std::cout << end << std::endl;
}

void TaskString::printTask()
{
	std::string greanColor = "\x1B[32m";
	std::string resetColor = "\033[0m";

	std::string textColor = isFinished == true ? greanColor : resetColor;

	std::cout << textColor;

	linePrint("|", "-", "+", "|", 2, 50);

	std::cout << "| " << getName() << std::setw(51 - getName().size()) << " + " << getPosition() << std::setw(50 - getPosition().size()) << " |" << std::endl;

	linePrint("|", "-", "+", "|", 2, 50);

	std::string finishTaskPrint = getTask();
	int countLine = 0;
	if (getTask().size() > 100)
	{
		for (int i = 99; i < getTask().size(); i = (99 * (countLine + 1)) + 6 * countLine)
		{
			finishTaskPrint.insert(i, std::string(" | \n| "));
			++countLine;
		}
	}
	else
	{
		finishTaskPrint = getTask();
	}

	int withLine = finishTaskPrint.size() < 100 ? 101 : ((101 * (countLine + 1)) + (4 * countLine));

	std::string stringTaskNum = "Task # " + std::to_string(taskNum);
	std::cout << "| " << "\x1B[33m" << stringTaskNum << textColor << std::setw(withLine - stringTaskNum.size()) << " |" << std::endl;

	std::cout << "| " << finishTaskPrint << std::setw(withLine - finishTaskPrint.size()) << " |" << std::endl;

	linePrint("|", "-", "+", "|", 2, 50);
	std::cout << "| " << dataString(dataStart) << std::setw(51 - dataString(dataStart).size()) << " + ";

	std::string finishTimePrint = isFinished == true ? dataString(dataEnd) : "In progress!";

	std::cout << finishTimePrint << std::setw(50 - finishTimePrint.size()) << " |" << std::endl;
	linePrint("|", "-", "+", "|", 2, 50);

	std::cout << resetColor;
}

void TaskString::checkInputString(std::string& input, std::string name)
{
	std::getline(std::cin, input);

	int charactersNum = name == "task" ? 400 : 50;

	if (input.size() > charactersNum)
	{
		std::cout << "\x1B[31mText is too long, please re-enter!\033[0m" << std::endl;
		checkInputString(input, name);
	}
	else return;
}

void TaskString::checkInputData(int& day, int& mounth, int& year)
{
	std::cout << "Day: ";
	std::cin >> day;
	std::cout << "Mounth: ";
	std::cin >> mounth;
	std::cout << "Year: ";
	std::cin >> year;

	if (std::cin.fail() || day < 1 || day > 31 || mounth < 1 || mounth > 12 || year < 2000 || year > 2100)
	{
		std::cout << "\x1B[31mIncorrect input data, please re-enter!\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		checkInputData(day, mounth, year);
	}
	else
	{
		std::cin.ignore();
		return;
	}
}

void TaskString::readData(std::string& readOne, std::string TypeData)
{
	int day;
	int mounth;
	int year;

	char separator = '/';
	int count = 0;

	if (TypeData == "startData")
	{
		std::string str;
		for (int i = 0; i <= readOne.size(); ++i)
		{
			char ch = readOne[i];
			if(ch == separator && count == 0)
			{
				day = stoi(str);
				str = "";
				count++;
			}
			else if(ch == separator && count == 1)
			{
				mounth = stoi(str);
				str = "";
				count++;
			}			
			else if(ch == '\0')
			{
				year = stoi(str);
				str = "";
				count++;
			}
			if(ch != separator)
			{
				str += ch;
			}
		}
		setStartData(day, mounth, year);
	}

	else if (TypeData == "endData")
	{
		if(readOne == "In progress!") 
		{
			isFinished = false;
			return;
		}

		std::string str;
		for (int i = 0; i <= readOne.size(); ++i)
		{
			char ch = readOne[i];
			if(ch == separator && count == 0)
			{
				day = stoi(str);
				str = "";
				count++;
			}
			else if(ch == separator && count == 1)
			{
				mounth = stoi(str);
				str = "";
				count++;
			}			
			else if(ch == '\0')
			{
				year = stoi(str);
				str = "";
				count++;
			}
			if(ch != separator)
			{
				str += ch;
			}
		}
		isFinished = true;
		setEndData(day, mounth, year);
	}
}