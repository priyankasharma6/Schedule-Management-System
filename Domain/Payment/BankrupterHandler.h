#pragma once

#include "PaymentHandler.h"
#include "../../Technical_Services/PaymentGateways/Bankrupter.h"

namespace Domain::Payment
{
	//Interface to the Bankrupter payment service
	class BankrupterHandler : public Domain::Payment::PaymentHandler
	{
	public:
		using PaymentHandler::PaymentHandler;

		BankrupterHandler();
		~BankrupterHandler() noexcept override;

		bool submitPayment(int amountRequired, int cardNum) override;
	private:
		Technical_Services::Bankrupter bankrupter = Technical_Services::Bankrupter();
	};
}