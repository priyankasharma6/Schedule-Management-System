#pragma once
//#include "Schedule.h"
#include <vector>
#include <string>
#include "Shift.h"
//#include "Schedule.h"

namespace Domain::Schedule
{
	class ScheduleHandler
	{
	public:
		ScheduleHandler() = default;

		virtual void addShift(int newStart, int newEnd) = 0;
		virtual void pickUpShift(std::string username, int newShift) = 0;

		virtual std::vector<Shift> getShiftList() = 0;

		virtual ~ScheduleHandler() noexcept;
	};

	inline ScheduleHandler::~ScheduleHandler() noexcept
	{}
}