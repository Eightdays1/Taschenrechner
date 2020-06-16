#include "Memory.h"

namespace calculator
{

	Memory::Memory(std::string input, double result) : m_input(pInput), m_reult(pResult)
	{
	}

	Memory::~Memory()
	{
	}

	std::string Memory::getInput()
	{
		return m_input;
	}

	double Memory::getResult()
	{
		return m_result;
	}
}

