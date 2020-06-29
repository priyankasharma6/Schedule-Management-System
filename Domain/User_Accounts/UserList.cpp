#include <iostream>
#include <vector>
#include <set>
#include <map>

#include "EmployeeAccount.h"
#include "UserList.h"

namespace Domain::User_Accounts
{

	//Overrides the constructer
	UserList::UserList()
	{
		//Creates a hardcoded list of employees
		//This is temporary, for testing purposes
		//In the future, EmployeeList will be retrieved from persistant data
		addEmployee("Master", EmployeeAccount("Master", 0));
		addEmployee("Super", EmployeeAccount("Visor", 1));
		addEmployee("Hello", EmployeeAccount("World", 2));
		addEmployee("ABCDE", EmployeeAccount("12345", 2));
	}

	//Returns the list of employees; getter method
	std::map<std::string, EmployeeAccount> UserList::getEmployeeList()
	{
		return employeeList;
	}

	//Adds an employee to the list
	void UserList::addEmployee(std::string newUsername, EmployeeAccount newEmployee)
	{
		std::pair<std::map<std::string, EmployeeAccount>::iterator, bool> success;
		success = employeeList.insert({ newUsername, newEmployee });
		if (success.second == false)
		{
			std::cout << newUsername << " already exists" << std::endl;
		}
	}

	void UserList::deleteEmployee(std::string employeeName)
	{
		//Removes the employee named employeeName from the map
		employeeList.erase(employeeName);
	}

	//authenticate - returns the role integer upon success, -1 upon failure
	int UserList::authenticate(std::string username, std::string password)
	{
		std::map<std::string, EmployeeAccount>::iterator it;

		//Attempts to find an account with the given username key
		it = employeeList.find(username);

		//If one is found, its password is checked
		if (it != employeeList.end())
		{
			if (it->second.getPassword().compare(password) == 0)
			{
				return it->second.getRole();
			}
		}

		return -1;
	}

	void UserList::printEmployeeList()
	{
		//Prints the username and the information of each employee
		//Prints everything at the moment; testing purposes
		for (auto it : employeeList)
		{
			std::cout << it.first << " " << it.second.getPassword() << " " << it.second.getRole() << std::endl;
		}
	}

	//Retrieves an EmployeeAccount's pointer to their notifications
	Domain::Notifications::NotificationList* UserList::getEmpNotes(std::string username)
	{
		Domain::Notifications::NotificationList* ptr = nullptr;

		std::map<std::string, EmployeeAccount>::iterator it;

		//Attempts to find an account with the given username key
		it = employeeList.find(username);

		//If one is found, its notifications are returned
		if (it != employeeList.end())
		{
			ptr = it->second.getEmpNotes();
		}

		return ptr;
	}
}