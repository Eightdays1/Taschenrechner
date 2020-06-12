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
		int * splitString(std::string pInputString);
	};
}

#endif // !NUMBER_H