#include "Memory.h"

Memory::Memory(String input, double result) : input(input), reult(result)
{
}

Memory::~Memory()
{
}

string Memory::getInput()
{
	return input;
}

double Memory::getResult()
{
	return result;
}
