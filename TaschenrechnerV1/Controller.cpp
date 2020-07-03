#include "Controller.h"
#include <iostream>
#include <vector>
#include <stack>
#include <debugapi.h>

namespace calculator
{
	std::vector<std::string> vInput{};


	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
	}

	//Method for initializing
	void Controller::init()
	{

		calculate("20+3");
	}

	//Is called by GUI if there is an Input. Input is given as String
	double Controller::calculate(std::string pInput)
	{
		m_input = pInput;
		//split String, store in Array/Vector
		splitString(pInput);
		//Convert String into UPN
		convertvInputToUPN();
		//(Create Objects and )solve UPN
		//Save Input and results in Memory
		//Return result
		return NULL;
	}

	void Controller::splitString(std::string pInputString) {

		std::string sLastNumber = "";
		for (int i = 0; i < pInputString.length(); i++) {
			std::string sCurrentElement(1, pInputString[i]);
			if (isNumber(sCurrentElement)) {
				if (sLastNumber == "") {
					sLastNumber = sCurrentElement;
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
		std::stack<std::string> input;
		std::vector<std::string> output;

		std::string Test;
		Test = vInput[1];
		for (auto i : vInput) {
			

		}

		//shunting-Yard-Algorithm

	}

	void Controller::solveUPN(/*std::vector<std::string> pUPNvector*/) {

		//solveUPN Algorithmus

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

