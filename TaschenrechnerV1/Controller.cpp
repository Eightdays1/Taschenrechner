#include "Controller.h"
#include <iostream>
#include <vector>
#include <stack>
#include <debugapi.h>
#include <stdio.h>

namespace calculator
{
	std::vector<std::string> vInput{};
	std::stack<std::string> stack;
	std::vector<std::string> output;
	bool Error = false;


	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
	}

	//Method for initializing
	void Controller::init()
	{

		calculate("20+3-50*8");
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
				sLastNumber = "";
				vInput.push_back(sCurrentElement);
			}
		}
	}

	//converts global vInput to UPN-Format(Prefix-notation)
	void Controller::convertvInputToUPN() {
		for (int i = 0; i < vInput.size(); i++)
		{
			const std::string token = vInput[i];

			if (isOperator(token))
			{
				const std::string o1 = token;

				if (!stack.empty())
				{
					std::string o2 = stack.top();

					while (isOperator(o2) &&
						((isLeftAssociative(o1) && Precedence(o1, o2) == 0) ||
							(Precedence(o1, o2) < 0)))
					{
						stack.pop();
						output.push_back(o2);

						if (!stack.empty())
							o2 = stack.top();
						else
							break;
					}
				}
				stack.push(o1);
			}
			else if (token == "(")
			{
				stack.push(token);
			}
			else if (token == ")")
			{
				std::string topToken = stack.top();

				while (topToken != "(")
				{
					output.push_back(topToken);
					stack.pop();

					if (stack.empty()) break;
					topToken = stack.top();
				}
				if (!stack.empty()) stack.pop();
				if (topToken != "(")
				{
					Error = true;
				}
			} 
			else
			{
				output.push_back(token);
			}
		}

		while (!stack.empty()){
			const std::string stackToken = stack.top();
			if (stackToken == ")" || stackToken == "(") Error = true;
			output.push_back(stackToken);
			stack.pop();
		}
	}
	//shunting-Yard-Algorithm
	

	void Controller::solveUPN(/*std::vector<std::string> pUPNvector*/) {

		//solveUPN Algorithmus

		std::stack<std::string> sStack;

		std::string sRight = "";
		std::string sLeft = "";
		std::string sResult = "";
		/*
		for each (std::string sInputString in vInput){
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
		*/
		

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

	//returns true
	bool Controller::isNumber(std::string pString) {
		for (int i = 0; i < pString.length(); i++) {
			if (!isOneDigitNumber(pString[i])) {
				return false;
			}
		}
		return true;
	}


	int Controller::valuePrecedence(std::string token) {
		if (token == "+") return 0;
		else if (token == "-") return 0;
		else if (token == "*") return 5;
		else if (token == "/") return 5;
	}
	
	int Controller::Precedence(std::string token1, std::string token2) {
		return valuePrecedence(token1) - valuePrecedence(token2);
		
	}

	bool Controller::isLeftAssociative(std::string pString) {
		if (pString == "+" || pString == "-" || pString == "*" || pString == "/") return true;
		else return false;
	}


	bool Controller::isOperator(std::string pString){
		if (pString == "+" || pString == "-" || pString == "*" || pString == "/" || pString == "^") return true;
		else return false;
	}


	std::string Controller::computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString) {

		//Objekte erzeugen und Berechnen
		return NULL;
	}

}

