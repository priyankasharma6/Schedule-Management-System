#pragma once
#include "UserTypeOptions.h"

namespace User_Interface::SchedulerInteraction
{
	class EmployeeOptions : public User_Interface::SchedulerInteraction::UserTypeOptions
	{
	public:
		using UserTypeOptions::UserTypeOptions;
		EmployeeOptions();

		//operations
		void displayList() override;
		bool selectOption(int chosenOption) override;

		~EmployeeOptions() noexcept override;
	};
}