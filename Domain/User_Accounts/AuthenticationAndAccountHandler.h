#pragma once

#include "EmployeeAccount.h"

namespace Domain::User_Accounts
{
	class AuthenticationAndAccountHandler
	{
	public:
		AuthenticationAndAccountHandler() = default;

		virtual int authenticate(std::string username, std::string password) = 0; //or return a user options type
		virtual void addEmployee(std::string newUsername, EmployeeAccount newEmployee) = 0;
		virtual void deleteEmployee(std::string employeeName) = 0;
		virtual void printEmployeeList() = 0;
		virtual Domain::Notifications::NotificationList* getEmpNotes(std::string username) = 0;

		virtual ~AuthenticationAndAccountHandler() noexcept;
	};

	inline AuthenticationAndAccountHandler::~AuthenticationAndAccountHandler() noexcept
	{}
}
