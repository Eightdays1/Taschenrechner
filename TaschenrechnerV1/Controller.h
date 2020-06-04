#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>
#include "TaschenrechnerV1.h"

namespace calculator
{
	using namespace std;

	class Controller
	{
	public:
		Controller();				//Konstruktor
		~Controller();				//Destruktor

		/*Method for initializing*/
		void init();

		/*Is called by GUI if there is an Input. Input is given as String*/
		void calculate(string pInput);
		//define Methods

	private:
		string input;
	};
}

#endif // !NUMBER_H