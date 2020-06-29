#include "TrustyPayHandler.h"
#include "../../Technical_Services/PaymentGateways/TrustyPay.h"

#include <iostream>

namespace Domain::Payment
{
	TrustyPayHandler::TrustyPayHandler()
	{

	}

	TrustyPayHandler::~TrustyPayHandler() noexcept
	{

	}

	bool TrustyPayHandler::submitPayment(int amountRequired, int cardNum)
	{
		std::cout << "Debug message: Using TrustyPay Payment Service" << std::endl;

		bool success = trustyPay.payment(cardNum, float(amountRequired));
		return success;
	}
}