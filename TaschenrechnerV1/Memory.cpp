#include "Memory.h"

namespace calculator
{

	Memory::Memory(string input, double result) : m_input(pInput), m_reult(pResult)
	{
	}

	Memory::~Memory()
	{
	}

	string Memory::getInput()
	{
		return m_input;
	}

	double Memory::getResult()
	{
		return m_result;
	}
}

