#pragma once

//Handler for user interface - an interface
namespace User_Interface ::SchedulerInteraction
{
	class UIHandler
	{
	public:
		UIHandler() = default;

		//operations
		virtual void runUI() = 0;

		virtual ~UIHandler() noexcept = 0;

	protected:
	};

	inline UIHandler::~UIHandler() noexcept
	{}
}