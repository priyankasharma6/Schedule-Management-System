#include "ManagerOptions.h"

#include <iostream>

namespace User_Interface::SchedulerInteraction
{
	ManagerOptions::ManagerOptions()
	{

	}

	ManagerOptions::~ManagerOptions() noexcept
	{

	}

	void ManagerOptions::displayList()
	{
		std::cout << "Manager Options:" << std::endl;
		std::cout << "1. Close System" << std::endl;
		std::cout << "2. Pick Up Shift" << std::endl;
		std::cout << "3. Manage Schedule" << std::endl;
		std::cout << "4. Manage Notifications" << std::endl;
	}

	bool ManagerOptions::selectOption(int chosenOption)
	{
		switch (chosenOption)
		{
		case 1:
			std::cout << "Closing the program..." << std::endl;
			return false;
			break;
		case 2:
			pickUpShift();
			return true;
			break;
		case 3:
			manageSchedule();
			return true;
			break;
		case 4:
			manageNotifications();
			return true;
			break;
		default:
			std::cout << "Closing the program..." << std::endl;
			return false;
			break;
		}
	}
}