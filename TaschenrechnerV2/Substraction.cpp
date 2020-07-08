#include "Substraction.h"

namespace calculator
{
	Substraction::Substraction(double pNum1, double pNum2)
	{
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}
	Substraction::~Substraction()
	{
	}
	double Substraction::solve()
	{
		return m_Num1 - m_Num2;
	}
}