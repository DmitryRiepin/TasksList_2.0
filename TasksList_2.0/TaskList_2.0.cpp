#include <iostream>
#include "TaskList.h"
#include "Menu.h"

using namespace std;

int main()
{
	cout << "\t Welcome to the Task List program! \n" << endl;

	bool repiteMainMenu = true;
	do
	{
		Menu main(MAIN);
		Menu second(SECOND);
		switch (main.menu())
		{
		case 1: // New Task list
		{
			TaskList task;
			bool repeatSecondMenu = true;
			do
			{
				switch (second.menu())
				{
				case 1: {task.addTask();
					break; }
				case 2: {task.finishTask(); break; }
				case 3: {task.printAll(); system("pause"); break; }
				case 4: {task.printProgressTask(); system("pause"); break; }
				case 5: {task.printFinishedTask(); system("pause"); break; }
				case 6: {repeatSecondMenu = false; break; }

				}
			} while (repeatSecondMenu);

			continue;
		}
		case 2: // Open Task list
		{
			Menu files(FILES);
			TaskList task(files.fileChoice());
			bool repeatSecondMenu = true;
			do
			{
				switch (second.menu())
				{
				case 1: {task.addTask();
					break; }
				case 2: {task.finishTask(); break; }
				case 3: {task.printAll(); system("pause"); break; }
				case 4: {task.printProgressTask(); system("pause"); break; }
				case 5: {task.printFinishedTask(); system("pause"); break; }
				case 6: {repeatSecondMenu = false; break; }

				}
			} while (repeatSecondMenu);

			continue;
		}
		case 3: repiteMainMenu = false; break;
		}
	} while (repiteMainMenu);

}



