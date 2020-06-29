#pragma once

#include <string>

namespace Technical_Services::Persistence
{
	class PersistanceHandler
	{
	public:
		PersistanceHandler() = default;
		virtual ~PersistanceHandler() noexcept;

		virtual void getStoredData() = 0;
	};

	inline PersistanceHandler::~PersistanceHandler() noexcept
	{}
}
