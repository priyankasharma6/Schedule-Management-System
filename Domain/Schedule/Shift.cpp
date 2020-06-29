#include "Shift.h"

namespace Domain
{
	Shift::Shift(int newStart, int newEnd, std::string newTakenBy)
	{
		startTime = newStart;
		endTime = newEnd;
		takenBy = newTakenBy;
	}

	std::string Shift::getTakenBy()
	{
		return takenBy;
	}

	int Shift::getStartTime()
	{
		return startTime;
	}

	int Shift::getEndTime()
	{
		return endTime;
	}

	void Shift::setTakenBy(std::string username)
	{
		takenBy = username;
	}
}