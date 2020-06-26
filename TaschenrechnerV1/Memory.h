#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>

namespace calculator
{
	class Memory
	{
	public:
		Memory(std::string pInput, double pResult);			//Konstruktor
		~Memory();										//Destruktor

		std::string getInput();
		double getResult();

	private:
		double m_result;
		std::string m_input;
	};
}


#endif