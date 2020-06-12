#include "Controller.h"
#include <iostream>

namespace calculator
{
	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
	}

	void Controller::init()
	{
		calculate("2+3");
	}

	void Controller::calculate(std::string pInput)
	{
		//split String, store in Array/Vector
		splitString(pInput);
		//Convert String into UPN
		//Create Objects and solve UPN
		//Return result
	}

	int * Controller::splitString(std::string pInputString) {
		char* tempChars = new char[pInputString.length() + 1] { 0 };
		strcpy(tempChars, pInputString.c_str());

		//Long version of resulting Array, coppy Values in shorter Array later:
		std::string* aInputArrayLong = new std::string[pInputString.length() + 1];


		

		return NULL;

	}

}

