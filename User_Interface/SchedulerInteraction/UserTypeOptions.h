#pragma once

#include <string>

#include "../../Domain/User_Accounts/UserList.h"
#include "../../Domain/User_Accounts/EmployeeAccount.h"
#include "../../Domain/Schedule/Schedule.h"
#include "../../Domain/Schedule/Shift.h"
#include "MainUI.h"

namespace User_Interface::SchedulerInteraction
{
	//Abstract class - implements functions for use cases, but option lists must be overridden
	class UserTypeOptions
	{
	public:
		UserTypeOptions() = default;

		virtual void displayList() = 0; //displays list of choices a user has
		virtual bool selectOption(int chosenOption) = 0; //checks the user's option against the list
		//true if the user selected a use case, false if they chose close

		//All use cases are defined here
		void addEmployee()
		{
			MainUI::loggingPtr->addLogItem("Starting to add Employee");

			std::string newUsername;
			std::string newPassword;
			int newRole;

			std::cout << "Enter the new username: ";
			std::cin >> newUsername;
			std::cout << "Enter the new password: ";
			std::cin >> newPassword;
			std::cout << "Enter the role number (0 for Admin, 1 for Manager, 2 for General Employee): ";
			std::cin >> newRole;

			MainUI::userListPtr->addEmployee(newUsername, Domain::User_Accounts::EmployeeAccount(newPassword, newRole));

			//Debug purposes
			MainUI::userListPtr->printEmployeeList();

			MainUI::loggingPtr->addLogItem("Successfully Added Employee");
		}

		//Manage Schedule use case
		void manageSchedule()
		{
			MainUI::loggingPtr->addLogItem("starting to manage schedule");

			std::vector<Domain::Shift> shiftList = MainUI::schedulePtr->getShiftList();
			displayShifts(shiftList);

			int newStart, newEnd;
			std::cout << "Adding a new shift..." << std::endl;
			std::cout << "Enter the new start time: ";
			std::cin >> newStart;
			std::cout << "Enter the new end time: ";
			std::cin >> newEnd;

			MainUI::schedulePtr->addShift(newStart, newEnd);

			shiftList = MainUI::schedulePtr->getShiftList();
			displayShifts(shiftList);

			MainUI::loggingPtr->addLogItem("Successfully managed schedule");
		}

		//Pick Up Shift use case
		void pickUpShift()
		{
			MainUI::loggingPtr->addLogItem("Starting pick up shift");

			std::vector<Domain::Shift> shiftList = MainUI::schedulePtr->getShiftList();
			displayShifts(shiftList);

			//Reads in chosen shift and takes it from the list
			int chosenShift;
			std::cout << "Enter the number of the desired shift: ";
			std::cin >> chosenShift;

			MainUI::schedulePtr->pickUpShift(MainUI::authUsername, chosenShift);

			shiftList = MainUI::schedulePtr->getShiftList();
			displayShifts(shiftList);

			MainUI::loggingPtr->addLogItem("Ending pick up shift");
		}

		void makePayment()
		{
			MainUI::loggingPtr->addLogItem("starting payment");

			std::cout << "Payment Plans:" << std::endl;
			std::vector<std::string> plans = MainUI::paymentPtr->getSupscriptionPlans();
			int count = 0;
			for (std::string p : plans)
			{
				std::cout << count << ". " << p << std::endl;
				count++;
			}

			std::cout << "Enter the number of the desired plan: ";
			int planChoice;
			std::cin >> planChoice;
			int amountPayRequired = MainUI::paymentPtr->choosePlan(planChoice);
			std::cout << "The payment will be: $" << amountPayRequired << std::endl;

			std::cout << "Enter your card number: ";
			int cardNum;
			std::cin >> cardNum;
			bool paySuccess = MainUI::paymentPtr->submitPayment(amountPayRequired, cardNum);

			if (paySuccess)
			{
				std::cout << "Payment Successful" << std::endl;
			}
			else
			{
				std::cout << "Payment did not go through" << std::endl;
			}

			MainUI::loggingPtr->addLogItem("ending payment");
		}

		//Allows user to view and save or delete notifications
		void manageNotifications()
		{
			MainUI::loggingPtr->addLogItem("Starting to manage notificaitons");

			//Retrieves a pointer to the user's NotificationList object
			Domain::Notifications::NotificationList* notePtr = MainUI::userListPtr->getEmpNotes(MainUI::authUsername);

			//Prints notifications and gives user an option to delete them
			std::vector<std::string> employeeNotifications = notePtr->getStoredNotifications();

			for (auto i = employeeNotifications.begin(); i != employeeNotifications.end();)
			{
				std::cout << *i << std::endl;
				std::cout << "Dismiss? (y/n): ";

				char userChoice;
				std::cin >> userChoice;
				if (userChoice == 'y')
				{
					i = employeeNotifications.erase(i);
				}
				else
				{
					i++;
				}
			}

			//Updates with all dismissed notifications deleted
			notePtr->setStoredNotifications(employeeNotifications);

			MainUI::loggingPtr->addLogItem("edning manage notifications");
		}

		virtual ~UserTypeOptions() noexcept;

	protected:
		//Method to display all the shifts
		void displayShifts(std::vector<Domain::Shift> shiftList)
		{
			int count = 0;

			for (Domain::Shift shift : shiftList)
			{
				std::cout << count << ". ";
				std::cout << shift.getStartTime() << " " << shift.getEndTime() << " " << shift.getTakenBy() << std::endl;
				count++;
			}
		}
	};

	inline UserTypeOptions::~UserTypeOptions() noexcept {}
}
