#include "BankrupterHandler.h"
#include "../../Technical_Services/PaymentGateways/Bankrupter.h"

#include <iostream>

namespace Domain::Payment
{
	BankrupterHandler::BankrupterHandler()
	{

	}

	BankrupterHandler::~BankrupterHandler() noexcept
	{

	}

	bool BankrupterHandler::submitPayment(int amountRequired, int cardNum)
	{
		std::cout << "Debug message: Using Bankrupter Payment Service" << std::endl;

		int success = bankrupter.payAttempt(amountRequired, cardNum);
		if (success >= 0)
			return true;
		else
			return false;
	}
}