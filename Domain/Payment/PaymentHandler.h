#pragma once

#include <string>
#include <vector>
//#include "TrustyPayHandler.h"

namespace Domain::Payment
{
	class PaymentHandler
	{
	public:
		PaymentHandler() = default;

		//Not defined, because different payment gateways will handle this differently
		virtual bool submitPayment(int amountRequired, int cardNum) = 0;

		//Defining these here - figure the amount a customer pays does not depend on the payment service
		std::vector<std::string> getSupscriptionPlans() //returns the available subscription plans
		{
			return subscriptionPlanList;
		}

		//Takes the selected plan number and returns the amount the customer must pay for it
		int choosePlan(int planNum) //returns the amount of pay required for the chosen plan
		{
			switch (planNum)
			{
			case 0:
				return 40;
			case 1:
				return 25;
			case 2:
				return 60;
			case 3:
				return 35;
			default:
				return 0;
				break;
			}
		}

		virtual ~PaymentHandler() noexcept;
	private:
		std::vector<std::string> subscriptionPlanList = { "Basic 2 years: $40", "Basic 1 year: $25", "Deluxe 2 years: $60", "Deluxe 1 year: $35" };
	};

	inline PaymentHandler::~PaymentHandler() noexcept {}
}