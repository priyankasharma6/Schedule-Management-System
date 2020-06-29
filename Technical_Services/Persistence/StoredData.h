#pragma once

#include "PersistanceHandler.h"

namespace Technical_Services::Persistence
{
	class StoredData : public Technical_Services::Persistence::PersistanceHandler
	{
	public:
		using PersistanceHandler::PersistanceHandler;
		StoredData();

		void getStoredData() override;
	};
}