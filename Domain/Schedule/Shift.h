#pragma once
#include <iostream>

namespace Domain
{
	class Shift
	{
	public:
		Shift(int newStart, int newEnd, std::string newTakenBy);
		std::string getTakenBy();
		void setTakenBy(std::string username);

		int getStartTime();
		int getEndTime();

	private:
		int startTime;
		int endTime;
		std::string takenBy;
	};
}
