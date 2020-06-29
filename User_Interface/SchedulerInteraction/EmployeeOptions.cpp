#include "EmployeeOptions.h"

#include <iostream>

namespace User_Interface::SchedulerInteraction
{
	EmployeeOptions::EmployeeOptions()
	{

	}

	EmployeeOptions::~EmployeeOptions() noexcept
	{

	}

	void EmployeeOptions::displayList()
	{
		std::cout << "Employee Options:" << std::endl;
		std::cout << "1. Close System" << std::endl;
		std::cout << "2. Pick Up Shift" << std::endl;
		std::cout << "3. Manage Notifications" << std::endl;
	}

	bool EmployeeOptions::selectOption(int chosenOption)
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