#include "Controller.h"
#include <iostream>
#include <vector>
#include "pch.h"

namespace calculator
{
	std::vector<std::string> vInput{};


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
		convertvInputToUPN();
		//(Create Objects and )solve UPN
		//Return result
	}

	void Controller::splitString(std::string pInputString) {
		//std::vector<std::string> vInput;

		std::string sLastNumber = "";
		for (int i = 0; i < pInputString.length(); i++) {
			std::string sCurrentElement(1, pInputString[i]);
			if (isNumber(sCurrentElement)) {
				if (sLastNumber == "") {
					sLastNumber == sCurrentElement;
				}
				else {
					sLastNumber.append(sCurrentElement);
				}
			}
			else if (sLastNumber == "") {
				vInput.push_back(sCurrentElement);
			}
			else {
				vInput.push_back(sLastNumber);
				vInput.push_back(sCurrentElement);
			}
		}
	}

	//converts global vInput to UPN-Format(Prefix-notation)
	void Controller::convertvInputToUPN() {

		//shunting-Yard-Algorithm

	}

	//returns true if String is one-digit Number
	bool Controller::isNumber(std::string pString) {
		if (pString == "0" || pString == "1" || pString == "2" || pString == "3" || pString == "4" || pString == "5" ||
			pString == "6" || pString == "7" || pString == "8" || pString == "9") {
			return true;
		}
		else {
			return false;
		}
	}

}

