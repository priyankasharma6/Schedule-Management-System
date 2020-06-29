#pragma once
#include "UserTypeOptions.h"

namespace User_Interface::SchedulerInteraction
{
	class AdminOptions : public User_Interface::SchedulerInteraction::UserTypeOptions
	{
	public:
		using UserTypeOptions::UserTypeOptions;
		AdminOptions();

		//operations
		void displayList() override;
		bool selectOption(int chosenOption) override;

		~AdminOptions() noexcept override;
	};
}