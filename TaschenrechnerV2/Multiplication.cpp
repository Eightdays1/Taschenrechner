#include "Multiplication.h"

namespace calculator
{
	Multiplication::Multiplication(double pNum1, double pNum2)
	{
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}
	Multiplication::~Multiplication()
	{
	}
	double Multiplication::solve()
	{
		return m_Num1 * m_Num2;
	}
}