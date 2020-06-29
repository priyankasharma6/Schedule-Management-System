#pragma once

#include "ScheduleHandler.h"
#include "Shift.h"

#include <vector>

namespace Domain::Schedule
{
	class Schedule : public Domain::Schedule::ScheduleHandler
	{
	public:
		using ScheduleHandler::ScheduleHandler;
		Schedule();
		virtual ~Schedule() {};
		void addShift(int newStart, int newEnd) override;
		void pickUpShift(std::string username, int newShift) override;

		std::vector<Shift> getShiftList() override;

	private:
		std::vector<Shift> shiftList;
	};
}