#include "Memory.h"

namespace calculator
{

	Memory::Memory(std::string pInput, std::string pResult) : m_input(pInput), m_result(pResult)
	{
	}

	Memory::~Memory()
	{
	}

	std::string Memory::getInput()
	{
		return m_input;
	}

	std::string Memory::getResult()
	{
		return m_result;
	}
}

