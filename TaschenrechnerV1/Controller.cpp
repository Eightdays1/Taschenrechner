#include "Controller.h"
#include "Addtition.h"
#include "Substraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"
#include "Memory.h"
#include <iostream>
#include <vector>
#include <stack>
#include <debugapi.h>

namespace calculator
{
	std::vector<std::string> vInput{};
	std::vector<Memory> vMemory{};


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
		m_result = solveUPN();
		//Save Input and results in Memory
		store(m_input, m_result);
		//Return result
		return NULL;
	}

	void Controller::splitString(std::string pInputString) {

		std::string sLastNumber = "";
		for (int i = 0; i < pInputString.length(); i++) {
			std::string sCurrentElement(1, pInputString[i]);
			if (isOneDigitNumber(sCurrentElement)) {
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

	std::string Controller::solveUPN() {

		std::stack<std::string> sStack;

		std::string sRight = "";
		std::string sLeft = "";
		std::string sResult = "";

		for each (std::string sInputString in vInput)
		{
			if (isNumber(sInputString)) {
				sStack.push(sInputString);
			}
			else {
				if (isBinaryOperator(sInputString)) {
					sRight = sStack.top();
					sStack.pop();
					sLeft = sStack.top();
					sStack.pop();
					sResult = computeStrings(sLeft, sRight, sInputString);
					sStack.push(sResult);
				}
			}
		}
		return sStack.top();

	}

	//returns true if String is one-digit Number
	bool Controller::isOneDigitNumber(std::string pString) {
		if (pString == "0" || pString == "1" || pString == "2" || pString == "3" || pString == "4" || pString == "5" ||
			pString == "6" || pString == "7" || pString == "8" || pString == "9") {
			return true;
		}
		else {
			return false;
		}
	}

	//returns true if Char is one-digit Number
	bool Controller::isOneDigitNumber(char pChar) {
		if (pChar == '0' || pChar == '1' || pChar == '2' || pChar == '3' || pChar == '4' || pChar == '5' ||
			pChar == '6' || pChar == '7' || pChar == '8' || pChar == '9') {
			return true;
		}
		else {
			return false;
		}
	}

	//returns true if String is multi-digit-Numer
	bool Controller::isNumber(std::string pString) {
		for (int i = 0; i < pString.length(); i++) {
			if (!isOneDigitNumber(pString[i])) {
				return false;
			}
		}
		return true;
	}

	bool Controller::isBinaryOperator(std::string pString) {
		if (pString == "+" || pString == "-" || pString == "*" || pString == "/" || pString == "^") {
			return true;
		}
		else {
			return false;
		}
	}

	//Creates Operation-Objects, runs solve() and the destuctor, returns Solution
	std::string Controller::computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString) {
		
		std::string sReturnString = "";
		std::string::size_type sz;
		double dLeftNum = std::stod(pLeftString, &sz);
		double dRightNum = std::stod(pRightString, &sz);

		if (pOperatorString == "+") {
			calculator::Addition add = calculator::Addition(dLeftNum, dRightNum);
			sReturnString = add.solve();
			add.~Addition();
		}
		else if (pOperatorString == "-") {
			calculator::Substraction sub = calculator::Substraction(dLeftNum, dRightNum);
			sReturnString = sub.solve();
			sub.~Substraction();
		}
		else if (pOperatorString == "*") {
			calculator::Multiplication mul = calculator::Multiplication(dLeftNum, dRightNum);
			sReturnString = mul.solve();
			mul.~Multiplication();
		}
		else if (pOperatorString == "/") {
			calculator::Division div = calculator::Division(dLeftNum, dRightNum);
			sReturnString = div.solve();
			div.~Division();
		}
		else if (pOperatorString == "^") {
			calculator::Power pwr = calculator::Power(dLeftNum, dRightNum);
			sReturnString = pwr.solve();
			pwr.~Power();
		}
		
		return sReturnString;
	}

	void Controller::store(std::string pInputString, std::string pResultString) {
		vMemory[vMemory.size()-1] = calculator::Memory(pInputString, pResultString);
	}

}

