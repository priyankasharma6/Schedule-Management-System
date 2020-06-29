#include <iostream>

#include "EmployeeAccount.h"

namespace Domain::User_Accounts
{
	//Overrides constructor to allow creation of new employee by putting in the attributes
	EmployeeAccount::EmployeeAccount(/*std::string newUsername,*/ std::string newPassword, int newRole)
	{
		password = newPassword;

		//If invalid role is inputed, defaults to 2 - employee level
		if (newRole < 0 || newRole > 2)
		{
			role = 2;
		}
		else
			role = newRole;

		empNotes = new Domain::Notifications::NotificationList();
	}

	std::string EmployeeAccount::getPassword()
	{
		return password;
	}

	int EmployeeAccount::getRole()
	{
		return role;
	}

	std::vector<std::string> EmployeeAccount::getNotifications()
	{
		return empNotes->getStoredNotifications();
	}

	Domain::Notifications::NotificationList* EmployeeAccount::getEmpNotes()
	{
		return empNotes;
	}
}