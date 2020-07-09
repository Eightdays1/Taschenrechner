#include "Controller.h"
#include "Addition.h"
#include "Substraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"
#include "Memory.h"
#include "windows.h"
#include "TaschenrechnerV2.h"
#include <iostream>
#include <vector>
#include <stack>
#include <debugapi.h>
#include <stdio.h>
#include <QtCore>

namespace calculator
{
	std::vector<std::string> vInput;
	std::stack<std::string> stack;
	std::vector<std::string> vOutput;
	bool Error = false;
	std::vector<Memory*> vMemory;
	bool bLoadHistory = 0;
	int iLoadHistoryEntryNr = 0;
	TaschenrechnerV2* Rechner;


	Controller::Controller(TaschenrechnerV2* pTaschenrechner)
	{
		Rechner = pTaschenrechner;
	}

	Controller::~Controller()
	{
	}

	//Method for initializing
	void Controller::init()
	{
		//calculate("20+35-13*2");
		//pInput = "20+35-13*2";
	}

	//Is called by GUI if there is an Input. Input is given as String
	QString Controller::calculate(std::string pInput)
	{
		bLoadHistory = 0;
		iLoadHistoryEntryNr = 0;
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
		return QString::fromStdString(m_result);
	}

	void Controller::splitString(std::string pInputString) {

		std::string sLastNumber = "";
		std::string sCurrentElement = "";

		for (int i = 0; i < pInputString.size(); i++) {
			sCurrentElement = pInputString[i];
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
		if (sCurrentElement != "") {
			vInput.push_back(sCurrentElement);
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
						vOutput.push_back(o2);

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
					vOutput.push_back(topToken);
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
				vOutput.push_back(token);
			}
		}

		while (!stack.empty()) {
			const std::string stackToken = stack.top();
			if (stackToken == ")" || stackToken == "(") Error = true;
			vOutput.push_back(stackToken);
			stack.pop();
		}
	}
	//shunting-Yard-Algorithm


	std::string Controller::solveUPN() {

		std::stack<std::string> sStack;

		std::string sRight = "";
		std::string sLeft = "";
		std::string sResult = "";
		
		for each (std::string sInputString in vOutput){
			if (isNumber(sInputString)) {
				sStack.push(sInputString);
			}
			else {
				if (isOperator(sInputString)) {
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

	bool Controller::isOperator(std::string pString) {
	if (pString == "+" || pString == "-" || pString == "*" || pString == "/" || pString == "^") return true;
	else return false;
	}

	//Creates Operation-Objects, runs solve() and the destuctor, returns Solution
	std::string Controller::computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString) {

	std::string sReturnString = "";
	std::string::size_type sz;
	double dLeftNum = std::stod(pLeftString, &sz);
	double dRightNum = std::stod(pRightString, &sz);

	if (pOperatorString == "+") {
		calculator::Addition add = calculator::Addition(dLeftNum, dRightNum);
		sReturnString = std::to_string(add.solve());
		add.~Addition();
	}
	else if (pOperatorString == "-") {
		calculator::Substraction sub = calculator::Substraction(dLeftNum, dRightNum);
		sReturnString = std::to_string(sub.solve());
		sub.~Substraction();
	}
	else if (pOperatorString == "*") {
		calculator::Multiplication mul = calculator::Multiplication(dLeftNum, dRightNum);
		sReturnString = std::to_string(mul.solve());
		mul.~Multiplication();
	}
	else if (pOperatorString == "/") {
		calculator::Division div = calculator::Division(dLeftNum, dRightNum);
		sReturnString = std::to_string(div.solve());
		div.~Division();
	}
	else if (pOperatorString == "^") {
		calculator::Power pwr = calculator::Power(dLeftNum, dRightNum);
		sReturnString = std::to_string(pwr.solve());
		pwr.~Power();
	}

	return sReturnString;
	}

	//creates and stores Memory Objects
	void Controller::store(std::string pInputString, std::string pResultString) {
			vMemory.emplace_back(&calculator::Memory(pInputString, pResultString));
	}

	//fkt zum speicher abrufen

	void Controller::load() {
		if (bLoadHistory) {
			if (iLoadHistoryEntryNr <= 0) {
				Rechner->showInput("Keine weitern Einträge");
				Rechner->showResult("Keine weiteren Einträge");
				return;
			}
			else {
				iLoadHistoryEntryNr--;
			}

		}
		else {
			iLoadHistoryEntryNr = vMemory.size();
			bLoadHistory = 1;
		}
		Rechner->showInput(vMemory[iLoadHistoryEntryNr]->getInput());
		Rechner->showResult(vMemory[iLoadHistoryEntryNr]->getResult());
	}

	

}