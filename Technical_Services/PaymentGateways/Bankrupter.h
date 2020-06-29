#pragma once
namespace Technical_Services
{
	class Bankrupter
	{
	public:
		Bankrupter();

		//Takes the card's number and payment amount, and returns a positive number if successful
		int payAttempt(int pay, int paycardNumber); 
	};
}