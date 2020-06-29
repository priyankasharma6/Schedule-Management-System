#include <iostream>

#include "User_Interface/SchedulerInteraction/UIHandler.h"
#include "User_Interface/SchedulerInteraction/MainUI.h"

int main()
{
	std::cout << "Starting program from main..." << std::endl;

	//creates a pointer to the main UI and runs it
	std::unique_ptr<User_Interface::SchedulerInteraction::UIHandler> uiPointer(new User_Interface::SchedulerInteraction::MainUI);
	uiPointer->runUI();

	return 0;
}