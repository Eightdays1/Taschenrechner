#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>

namespace claculator
{

	using namespace std;

	class Memory
	{
	public:
		Memory(string pInput, double pResult);			//Konstruktor
		~Memory();										//Destruktor

		string getInput();
		double getResult();

	private:
		double m_numberresult;
		string m_input;
	};
}


#endif // !NUMBER_H