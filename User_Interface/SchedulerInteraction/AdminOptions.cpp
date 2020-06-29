#include "AdminOptions.h"

#include <iostream>

namespace User_Interface :: SchedulerInteraction
{
	AdminOptions::AdminOptions()
	{

	}

	AdminOptions::~AdminOptions() noexcept
	{

	}

	void AdminOptions::displayList()
	{
		std::cout << "Admin Options:" << std::endl;
		std::cout << "1. Close System" << std::endl;
		std::cout << "2. Add Account" << std::endl;
		std::cout << "3. Pick Up Shift" << std::endl;
		std::cout << "4. Manage Schedule" << std::endl;
		std::cout << "5. Make Payment" << std::endl;
		std::cout << "6. Manage Notifications" << std::endl;
	}

	bool AdminOptions::selectOption(int chosenOption)
	{
		switch (chosenOption)
		{
		case 1:
			std::cout << "Closing the program..." << std::endl;
			return false;
			break;
		case 2:
			addEmployee();
			return true;
			break;
		case 3:
			pickUpShift();
			return true;
			break;
		case 4:
			manageSchedule();
			return true;
			break;
		case 5:
			makePayment();
			return true;
			break;
		case 6:
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