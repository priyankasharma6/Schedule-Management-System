#pragma once

#include <string>

namespace Technical_Services::Logging
{
	class LoggingHandler
	{
	public:
		LoggingHandler() = default;
		virtual ~LoggingHandler() noexcept;

		virtual void addLogItem(std::string logItem) = 0;
	};

	inline LoggingHandler::~LoggingHandler() noexcept
	{}
}
