#include "Controller.h"
#include "TaschenrechnerV1.cpp"

namespace calculator
{
	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
	}

	Controller::init()
	{
		this.calculate("2+3");
	}

	void Controller::calculate(string pInput)
	{
		//split String, store in Array
		//Convert String into UPN
		//Create Objects and solve UPN
	}

}

