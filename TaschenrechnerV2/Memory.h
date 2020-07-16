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
		Memory(std::string pInput, std::string pResult);			//Konstruktor
		~Memory();													//Destruktor

		std::string getInput();
		std::string getResult();

		std::string m_result;
		std::string m_input;
	private:
		
	};
}


#endif