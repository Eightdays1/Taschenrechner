#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>
#include "TaschenrechnerV1.h"

namespace calculator
{
	class Controller
	{
	public:
		Controller();				//Konstruktor
		~Controller();				//Destruktor

		/*Method for initializing*/
		void init();

		/*Is called by GUI if there is an Input. Input is given as String*/
		void calculate(std::string pInput);
		//define Methods

	private:
		std::string m_input;
		void splitString(std::string pInputString);
		void convertvInputToUPN();
		void solveUPN(std::vector<std::string> pUPNvector);
		bool isNumber(std::string pString);
	};
}

#endif // !NUMBER_H