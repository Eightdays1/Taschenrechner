#include "Memory.h"

namespace calculator
{

	Memory::Memory(std::string pInput, double pResult) : m_input(pInput), m_result(pResult)
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

