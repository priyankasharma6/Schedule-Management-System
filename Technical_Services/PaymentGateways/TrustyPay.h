#pragma once

namespace Technical_Services
{
	class TrustyPay
	{
	public:
		TrustyPay();
		bool payment(int cardNo, float charge); //Takes the card's number and payment amount, and returns true if successful
	};
}