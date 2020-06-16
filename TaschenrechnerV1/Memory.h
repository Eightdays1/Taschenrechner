#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>

namespace claculator
{
	class Memory
	{
	public:
		Memory(std::string pInput, double pResult);			//Konstruktor
		~Memory();										//Destruktor

		std::string getInput();
		double getResult();

	private:
		double m_numberresult;
		std::string m_input;
	};
}


#endif // !NUMBER_H