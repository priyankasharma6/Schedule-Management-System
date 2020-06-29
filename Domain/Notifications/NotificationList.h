#pragma once
#include <vector>
#include <string>

namespace Domain::Notifications
{
	class NotificationList
	{
	public:
		NotificationList();
		void addNotification(std::string newNote);
		std::vector<std::string> getStoredNotifications();
		void setStoredNotifications(std::vector<std::string> newNotes);
	private:
		std::vector <std::string> storedNotifications;
	};
}