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
		Number(double pNumber);			//Konstruktor
		~Number();						//Destruktor

		double getNumber();

	private:
		double m_number;
	};
}
#endif // !NUMBER_H