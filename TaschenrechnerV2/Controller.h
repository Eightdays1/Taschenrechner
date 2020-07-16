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
		Controller();
		Controller(TaschenrechnerV2* pTaschenrechner);		//Konstruktor
		~Controller();										//Destruktor

		//Is called by GUI if there is an Input. Input is given as String
		QString calculate(std::string pInput);
		//define Methods
		void registerInput(std::string pInput);

	private:
		//Attributes
		std::string m_input;
		std::string m_result;

		//Methods only used by Methods in "Controller"
		void checkSyntax();
		void splitString(std::string pInputString);
		void convertvInputToUPN();
		std::string solveUPN();
		bool isOneDigitNumber(std::string pString);
		bool isOneDigitNumber(char pChar);
		bool isNumber(std::string pString);
		int valuePrecedence(std::string token);
		int precedence(std::string token1, std::string token2);
		bool isLeftAssociative(std::string pString);
		bool isOperator(std::string pString);
		bool isOperator(char pChar);
		std::string computeStrings(std::string pLeftString, std::string pRightString, std::string pOperatorString);
		void store(std::string pInputString, std::string pResultString);
		void load();
		std::string stripDecimals(std::string);
		void showInputOnGUI(QString pString);


	};
}

#endif