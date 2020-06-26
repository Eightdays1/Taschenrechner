#include "Division.h"

namespace calculator
{
	Division::Division(double pNum1, double pNum2)
	{
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}
	Division::~Division()
	{
	}
	double Division::solve()
	{
		return m_Num1 / m_Num2;
	}
}