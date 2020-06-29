#pragma once

#include "LoggingHandler.h"

namespace Technical_Services::Logging
{
	class LoggerStub : public Technical_Services::Logging::LoggingHandler
	{
	public:
		using LoggingHandler::LoggingHandler;
		LoggerStub();

		void addLogItem(std::string logItem) override;
	};
}