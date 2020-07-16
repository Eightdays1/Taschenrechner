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
	std::vector<std::string> vInput;			//Input after "splitString"
	std::vector<std::string> vInputAsUPN;		//Input in Prefix-Notation after "convertToUPN"
	QString tResult;
	bool Error = false;
	std::vector<Memory*> vMemory;				//Stores Pointers to Memory-Objects
	bool bLoadHistory = false;						//If 1, a memory-Object was loaded as last action
	int iLoadHistoryEntryNr = 0;				//Index of las loaded Memory-Object
	std::string sInputString;					//Input as String, build by "registerInput"
	TaschenrechnerV2* calc;						//"Calc" Object, im Konstruktor übergeben


	Controller::Controller(TaschenrechnerV2* pTaschenrechner)
	{
		calc = pTaschenrechner;
	}

	Controller::Controller() {

	}

	Controller::~Controller()
	{
	}

	//Is called by GUI if there is an Input. Input is given as String
	QString Controller::calculate(std::string pInput)
	{
		bLoadHistory = false;
		iLoadHistoryEntryNr = 0;
		m_input = pInput;
		vInput = {};
		vInputAsUPN = {};

		//split String, store in Array/Vector
		splitString(pInput);
		//Check for Syntaxerror
		if (vInput.size() > 1) {
			checkSyntax();
			//Convert String into UPN
			convertvInputToUPN();
			//(Create Objects and )solve UPN
			m_result = solveUPN();
			//Strip unnessecarry decimals
			m_result = StripDecimals(m_result);
			//Save Input and results in Memory
		}
		else if (isOneDigitNumber(vInput[0]) && vInput.size() == 1) {
			m_result = StripDecimals(vInput[0]);
		}
		else {
			Error = true;
		}
		store(m_input, m_result);
		//Return result
		return QString::fromStdString(m_result);
	}

	void Controller::checkSyntax() {
		std::string test = "";
		//Check for "x/0"
		for (int i = 1; i < vInput.size(); i++) {
			if (vInput[i - 1] == "/" && vInput[i] == "0") {
				Error = true;
			}
		}
	}

	//splits String into Numbers and Operstors, stores them in global Vector vInput
	void Controller::splitString(std::string pInputString) {

		std::string sLastNumber = "";
		std::string sCurrentElement = "";

		for (int i = 0; i < pInputString.size(); i++) {
			sCurrentElement = pInputString[i];
			if (isOneDigitNumber(sCurrentElement) || sCurrentElement == ".") {
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
		if (sLastNumber != "") {
			vInput.push_back(sLastNumber);
		}
	}

	//converts global vInput to UPN-Format(Prefix-notation)
	void Controller::convertvInputToUPN() {
		std::stack<std::string> stack;
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
						vInputAsUPN.push_back(o2);

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
					vInputAsUPN.push_back(topToken);
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
				vInputAsUPN.push_back(token);
			}
		}

		while (!stack.empty()) {
			const std::string stackToken = stack.top();
			if (stackToken == ")" || stackToken == "(") Error = true;
			vInputAsUPN.push_back(stackToken);
			stack.pop();
		}
	}

	//Solve UPN by creating Operator-Objects, returns std::string
	std::string Controller::solveUPN() {

		std::stack<std::string> sStack;

		std::string sRight = "";
		std::string sLeft = "";
		std::string sResult = "";
		
		for each (std::string sInputString in vInputAsUPN){
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

	//Creates Operation-Objects, runs solve() and the destuctor, returns Solution
	std::string Controller::computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString) {

		std::string sReturnString = "";
		std::string::size_type sz;
		double dLeftNum = std::stod(pLeftString, &sz);
		double dRightNum = std::stod(pRightString, &sz);


		try {
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
				if (dRightNum == 0) {
					throw std::runtime_error("Math error: Attempted to divide by Zero");
				}
				else {
					calculator::Division div = calculator::Division(dLeftNum, dRightNum);
					sReturnString = std::to_string(div.solve());
					div.~Division();
				}
			}
			else if (pOperatorString == "^") {
				calculator::Power pwr = calculator::Power(dLeftNum, dRightNum);
				sReturnString = std::to_string(pwr.solve());
				pwr.~Power();
			}
		}

		catch (std::runtime_error e) {
			calc->showResult(QString::fromStdString(e.what()));
		}

		return sReturnString;
	}

	//creates and stores Memory Objects
	void Controller::store(std::string pInputString, std::string pResultString) {
		vMemory.emplace_back(new calculator::Memory(pInputString, pResultString));
	}

	//loads next History-Elemt with each successive call
	void Controller::load() {
		if (bLoadHistory) {
			if (iLoadHistoryEntryNr <= 0) {
				calc->showInput("Keine weitern Einträge");
				calc->showResult("Keine weiteren Einträge");
				return;
			}
			else {
				iLoadHistoryEntryNr--;
			}

		}
		else {
			iLoadHistoryEntryNr = vMemory.size();
			bLoadHistory = true;
		}

		calc->showInput(QString::fromStdString(vMemory[iLoadHistoryEntryNr]->getInput()));
		calc->showResult(QString::fromStdString(vMemory[iLoadHistoryEntryNr]->getResult()));
	}

	//gets Input from TaschenrechnerV2, stores it in global sInputString
	void Controller::registerInput(std::string pInput) {
		if (pInput == "enter") {
			if (sInputString != "") {
				tResult = calculate(sInputString);
				calc->showInput(QString::fromStdString(sInputString));
				sInputString = "";
				calc->showResult(tResult);
			}
		}
		else if (pInput == "clear") {
			tResult = "0";
			calc->showResult(tResult);
			sInputString = "";
			calc->showInput(QString::fromStdString(sInputString));
		}
		else if (pInput == "deleteLastNum") {
			sInputString = sInputString.substr(0, sInputString.size() - 1);
			calc->showInput(QString::fromStdString(sInputString));
		}
		else if (pInput == "history") {
			load();
		}
		else if (pInput == "ans") {
			sInputString.append(tResult.toStdString());
			calc->showInput(QString::fromStdString(sInputString));
		}
		else if ((sInputString == "" || isOperator(sInputString[sInputString.size()])) && pInput == ".")  {
			sInputString = "0.";
			calc->showInput(QString::fromStdString(sInputString));
		}
		else if (sInputString == "" && !isOperator(pInput)) {
			sInputString = pInput;
			calc->showInput(QString::fromStdString(sInputString));
		}
		else if (sInputString == "" && isOperator(pInput)) {
			sInputString = tResult.toStdString() + pInput;
			calc->showInput(QString::fromStdString(sInputString));
		}
		else {
			sInputString.append(pInput);
			calc->showInput(QString::fromStdString(sInputString));
		}
	}


	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//HELPER-FUNCTIONS
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
			if (!isOneDigitNumber(pString[i]) && pString[i] != '.') {
				return false;
			}
		}
		return true;
	}

	//returns int accounting to Precedence of Operator
	int Controller::valuePrecedence(std::string token) {
		if (token == "+") return 0;
		else if (token == "-") return 0;
		else if (token == "*") return 5;
		else if (token == "/") return 5;
		return 0;
	}

	//returns int accounting to difference of Precedences of Operator
	int Controller::Precedence(std::string token1, std::string token2) {
		return valuePrecedence(token1) - valuePrecedence(token2);
	}

	//returns true if Oerator is left-associative
	bool Controller::isLeftAssociative(std::string pString) {
		if (pString == "+" || pString == "-" || pString == "*" || pString == "/") return true;
		else return false;
	}

	//returns true if paramerter-String is binary Operator
	bool Controller::isOperator(std::string pString) {
		if (pString == "+" || pString == "-" || pString == "*" || pString == "/" || pString == "^") {
			return true;
		}
		else {
			return false;
		}
	}

	//returns true if Char is Operator
	bool Controller::isOperator(char pChar) {
		if (pChar == '+' || pChar == '-' || pChar == '*' || pChar == '/' || pChar == '^') {
			return true;
		}
		else {
			return false;
		}
	}

	//Strips appending Zeros after Decimalpoint
	std::string Controller::StripDecimals(std::string pString) {
		bool bFoundDot = false;
		bool bFoundNotZeroDigit = false;
		for each (char c in pString) {
			if (c == '.') {
				bFoundDot = true;
				break;
			}
		}
		if (bFoundDot) {
			for (int i = pString.size() - 1; i >= 0; i--) {
				if (pString[i] != '0' && pString[i] != '.') {
					bFoundNotZeroDigit = true;
				}
				else if (bFoundNotZeroDigit == false && (pString[i] == '0' || pString[i] == '.')) {
					if (pString[i] == '.') {
						bFoundNotZeroDigit = true;
					}
					pString.pop_back();
				}
			}
		}
		return pString;
	}


}