#pragma once
#include <iostream>
#include <vector>
#include "../Notifications/NotificationList.h"

namespace Domain::User_Accounts
{
	//Represents an employee account - a collection of a username, password, role, and other information
	class EmployeeAccount
	{
	public:
		EmployeeAccount(std::string newPassword, int newRole);
		virtual ~EmployeeAccount() {}

		//Getter methods
		std::string getPassword();
		int getRole();

		std::vector<std::string> getNotifications();
		Domain::Notifications::NotificationList* getEmpNotes();

	private:
		std::string password;
		int role = -1; //0 for admin, 1 for manager, 2 for employee
		//pointer to notification object
		Domain::Notifications::NotificationList* empNotes;
		//more attributes could be added in the future
	};
}