#include "Memory.h"

namespace calculator
{

	Memory::Memory(std::string pInput, std::string pResult)
	{
		this->m_input = pInput;
		this->m_result = pResult;
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

