#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "TaskString.h"

class TaskList
{
private:
	std::vector<TaskString> taskLists;
	std::string fileName;

	void readFile();
	void saveTaskList();
public:
	TaskList();	
	TaskList(std::string fileName);
	~TaskList();
	
	void addTask();
	void finishTask();

	const void printAll();
	const void printProgressTask();
	const void printFinishedTask();
};

