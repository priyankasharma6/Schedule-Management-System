#pragma once
#include <iostream>
#include <vector>
#include <set> //???
#include <map>

#include "AuthenticationAndAccountHandler.h"
#include "EmployeeAccount.h"

namespace Domain::User_Accounts
{
	//A class that represents a list of users
	class UserList : public Domain::User_Accounts::AuthenticationAndAccountHandler
	{
	public:
		using AuthenticationAndAccountHandler::AuthenticationAndAccountHandler;

		UserList();
		virtual ~UserList() {}

		int authenticate(std::string username, std::string password) override;
		std::map<std::string, EmployeeAccount> getEmployeeList();
		void addEmployee(std::string newUsername, EmployeeAccount newEmployee) override;
		void deleteEmployee(std::string employeeName) override;
		void printEmployeeList() override;

		Domain::Notifications::NotificationList* getEmpNotes(std::string username) override;

	private:
		std::map<std::string, EmployeeAccount> employeeList;
	};
}
