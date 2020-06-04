#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>

namespace calculator
{
	using namespace std;
	class Number
	{
	public:
		Number(double number);			//Konstruktor
		~Number();						//Destruktor

		double getNumber();

	private:
		double number;
	};
}
#endif // !NUMBER_H