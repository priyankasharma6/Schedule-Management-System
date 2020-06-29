#include "NotificationList.h"

namespace Domain::Notifications
{
	NotificationList::NotificationList()
	{
		//Default messages placed into all employees accounts
		//Debug purposes

		addNotification("Hi, welcome to Scheduler!");
		addNotification("These messages are for testing the software!");
	}

	void NotificationList::addNotification(std::string newNote)
	{
		storedNotifications.push_back(newNote);
	}

	std::vector<std::string> NotificationList::getStoredNotifications()
	{
		return storedNotifications;
	}

	void NotificationList::setStoredNotifications(std::vector<std::string> newNotes)
	{
		storedNotifications = newNotes;
	}
}