#include <iostream>

#include "MainUI.h"

#include "UserTypeOptions.h"
#include "AdminOptions.h"
#include "EmployeeOptions.h"
#include "ManagerOptions.h"

#include "../../Domain/User_Accounts/AuthenticationAndAccountHandler.h"
#include "../../Domain/User_Accounts/UserList.h"

#include "../../Domain/User_Accounts/EmployeeAccount.h"

#include "../../Domain/Schedule/ScheduleHandler.h"
#include "../../Domain/Schedule/Schedule.h"

#include "../../Technical_Services/Logging/LoggingHandler.h"
#include "../../Technical_Services/Logging/LoggerStub.h"

#include <tuple>

//possible to have different ui classes for the different use cases?
namespace User_Interface::SchedulerInteraction
{
	//Series of static variables to simulate singleton.  Subject to change.	
	std::unique_ptr<Technical_Services::Logging::LoggingHandler> MainUI::loggingPtr;
	std::unique_ptr<Technical_Services::Persistence::PersistanceHandler> MainUI::persistPtr;

	std::unique_ptr<Domain::User_Accounts::AuthenticationAndAccountHandler> MainUI::userListPtr;
	std::unique_ptr<Domain::Schedule::ScheduleHandler> MainUI::schedulePtr;
	std::unique_ptr<Domain::Payment::PaymentHandler> MainUI::paymentPtr;
	std::string MainUI::authUsername; //Contains the username when authentication succeeds

	MainUI::MainUI()
	{

	}

	MainUI::~MainUI() noexcept
	{

	}

	void MainUI::runUI()
	{
		std::cout << "UI running" << std::endl;

		//These are pointers to interfaces.  Act a bit like a singeton at the moment
		//Subject to change in the future.
		userListPtr = std::unique_ptr<Domain::User_Accounts::AuthenticationAndAccountHandler> (new Domain::User_Accounts::UserList);
		schedulePtr = std::unique_ptr<Domain::Schedule::ScheduleHandler> (new Domain::Schedule::Schedule);

		//Change payment gateways here
		paymentPtr = std::unique_ptr<Domain::Payment::PaymentHandler>(new Domain::Payment::BankrupterHandler);
		//paymentPtr = std::unique_ptr<Domain::Payment::PaymentHandler>(new Domain::Payment::TrustyPayHandler);

		loggingPtr = std::unique_ptr <Technical_Services::Logging::LoggingHandler> (new Technical_Services::Logging::LoggerStub);
		persistPtr = std::unique_ptr <Technical_Services::Persistence::PersistanceHandler>(new Technical_Services::Persistence::StoredData);

		std::string username, password;
		std::cout << "Enter username: ";
		std::cin >> username;
		std::cout << "Enter password: ";
		std::cin >> password;

		std::cout << "" << std::endl;

		int authenticatedRole = userListPtr->authenticate(username, password);

		//Check if authentication was successful.  If not, skips over menu options
		std::unique_ptr<User_Interface::SchedulerInteraction::UserTypeOptions> optionMenuPtr;

		switch (authenticatedRole)
		{
		case 0:
			optionMenuPtr = std::unique_ptr<User_Interface::SchedulerInteraction::UserTypeOptions>(new User_Interface::SchedulerInteraction::AdminOptions);
			break;
		case 1:
			optionMenuPtr = std::unique_ptr<User_Interface::SchedulerInteraction::UserTypeOptions>(new User_Interface::SchedulerInteraction::ManagerOptions);
			break;
		case 2:
			optionMenuPtr = std::unique_ptr<User_Interface::SchedulerInteraction::UserTypeOptions>(new User_Interface::SchedulerInteraction::EmployeeOptions);
			break;
		default:
			//Indicates a failed login
			std::cout << "Authentication failed" << std::endl;
			break;
		}

		authUsername = username;

		if (optionMenuPtr)
		{
			bool loop = true;
			while (loop)
			{
				//Will loop until close is selected
				optionMenuPtr->displayList();
				int userChoice;
				std::cin >> userChoice;
				std::cout << "" << std::endl;
				loop = optionMenuPtr->selectOption(userChoice);
				std::cout << "" << std::endl;
			}
		}
	}
}