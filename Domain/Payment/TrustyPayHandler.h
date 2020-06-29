#pragma once

#include "PaymentHandler.h"
#include "../../Technical_Services/PaymentGateways/TrustyPay.h"

namespace Domain::Payment
{
	//Interface to the TrustyPay payment service
	class TrustyPayHandler : public Domain::Payment::PaymentHandler
	{
	public:
		using PaymentHandler::PaymentHandler;

		TrustyPayHandler();
		~TrustyPayHandler() noexcept override;

		bool submitPayment(int amountRequired, int cardNum) override;
	private:
		Technical_Services::TrustyPay trustyPay = Technical_Services::TrustyPay();
	};
}