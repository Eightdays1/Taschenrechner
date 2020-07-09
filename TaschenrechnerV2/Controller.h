#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>
#include "TaschenrechnerV2.h"

namespace calculator
{
	class Controller
	{
	public:
		Controller(TaschenrechnerV2 pTaschenrechner);		//Konstruktor
		~Controller();										//Destruktor

		/*Method for initializing*/
		void init();

		/*Is called by GUI if there is an Input. Input is given as String*/
		QString calculate(std::string pInput);
		//define Methods

	private:
		//Attributes
		std::string m_input;
		std::string m_result;

		//Methods
		void splitString(std::string pInputString);
		void convertvInputToUPN();
		std::string solveUPN(/*std::vector<std::string> pUPNvector*/);
		bool isOneDigitNumber(std::string pString);
		bool isOneDigitNumber(char pChar);
		bool isNumber(std::string pString);
		int valuePrecedence(std::string token);
		int Precedence(std::string token1, std::string token2);
		bool isLeftAssociative(std::string pString);
		bool isOperator(std::string pString);
		std::string computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString);
		void store(std::string pInputString, std::string pResultString);
		void Controller::load();

	};
}

#endif