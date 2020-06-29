#pragma once
#include "UserTypeOptions.h"

namespace User_Interface::SchedulerInteraction
{
	class ManagerOptions : public User_Interface::SchedulerInteraction::UserTypeOptions
	{
	public:
		using UserTypeOptions::UserTypeOptions;
		ManagerOptions();

		//operations
		void displayList() override;
		bool selectOption(int chosenOption) override;

		~ManagerOptions() noexcept override;
	};
}