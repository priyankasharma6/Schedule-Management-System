#include "Schedule.h"
#include "Shift.h"

#include "../../User_Interface/SchedulerInteraction/MainUI.h"

#include <vector>

namespace Domain::Schedule
{
	Schedule::Schedule()
	{
		//Temporary, for debug purposes
		//In future would retrieve Schedule from persistance
		addShift(1, 2);
		addShift(3, 4);
		addShift(3, 4);
		addShift(5, 6);
		pickUpShift("Master", 3);

		//User_Interface::SchedulerInteraction::MainUI::persistPtr->getStoredData();
		//Maybe something like that, but currently this crashes the program due to being created before MainUI is
		//completely initialized
	}

	//Creates a new, untaken shift
	void Schedule::addShift(int newStart, int newEnd)
	{
		Shift newShift = Shift(newStart, newEnd, "");
		shiftList.push_back(newShift);
	}

	//Picks up a shift by editing the takenBy of the shift
	void Schedule::pickUpShift(std::string username, int newShift)
	{
		if (shiftList.at(newShift).getTakenBy().compare("") == 0)
		{
			shiftList.at(newShift).setTakenBy(username);
		}
		else
		{
			//The shift is already taken
		}
	}

	std::vector<Shift> Schedule::getShiftList()
	{
		return shiftList;
	}
}