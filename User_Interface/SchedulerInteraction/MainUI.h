#pragma once

#include "UIHandler.h"
#include "../../Domain/User_Accounts/AuthenticationAndAccountHandler.h"
#include "../../Domain/Schedule/ScheduleHandler.h"
#include <tuple>
#include "../../Domain/Payment/PaymentHandler.h"
#include "../../Domain/Payment/TrustyPayHandler.h"
#include "../../Domain/Payment/BankrupterHandler.h"

#include "../../Technical_Services/Logging/LoggingHandler.h"
#include "../../Technical_Services/Logging/LoggerStub.h"

#include "../../Technical_Services/Persistence/PersistanceHandler.h"
#include "../../Technical_Services/Persistence/StoredData.h"

namespace User_Interface::SchedulerInteraction
{
	class MainUI : public User_Interface::SchedulerInteraction::UIHandler
	{
	public:
		using UIHandler::UIHandler;
		MainUI();

		static std::unique_ptr<Technical_Services::Logging::LoggingHandler> loggingPtr;
		static std::unique_ptr<Technical_Services::Persistence::PersistanceHandler> persistPtr;

		static std::unique_ptr<Domain::User_Accounts::AuthenticationAndAccountHandler> userListPtr;
		static std::unique_ptr<Domain::Schedule::ScheduleHandler> schedulePtr;
		static std::unique_ptr<Domain::Payment::PaymentHandler> paymentPtr;
		static std::string authUsername;

		//operations - override UIHandler
		void runUI() override;

		~MainUI() noexcept override;

	};
}
