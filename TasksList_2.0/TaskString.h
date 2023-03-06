#pragma once
#include <string>
#include <vector>

struct Data
{
	int Day;
	int Mounth;
	int Year;
};


class TaskString
{
private:
	std::string name;
	std::string position;
	std::string task;
	Data dataStart;
	Data dataEnd;
	int taskNum = 0;
	bool isFinished;

	
	void linePrint(std::string start, std::string middle, std::string cross, std::string end, int count, int len);

	void checkInputString(std::string& input, std::string name);
	void checkInputData(int& day, int& mounth, int& year);

public:
	std::string getName() { return name; }
	std::string getPosition() { return position; }
	std::string getTask() { return task; }
	Data getStartData() { return dataStart; }
	Data getEndData() { return dataEnd; }
	int getTaskNum() { return taskNum; }
	bool getIsFinished() { return isFinished; }

	void setName(const std::string inputName) { name = inputName; }
	void setPosition(const std::string inputPosition) { position = inputPosition; }
	void setTask(const std::string inputTask) { task = inputTask; }
	void setStartData(const int day, const int mounth, const int year) { dataStart.Day = day; dataStart.Mounth = mounth; dataStart.Year = year; }
	void setEndData(const int day, const int mounth, const int year) { dataEnd.Day = day; dataEnd.Mounth = mounth; dataEnd.Year = year; }
	void setTaskNum(const int num) { taskNum = num; }

	std::string dataString(const Data& data);

	void createTask();
	void closeTask();

	void readData(std::string &readOne, std::string TypeData);

	void printTask();

};



