#include "Addtition.h"

namespace calculator
{
	Addition::Addition(double pNum1, double pNum2)
	{
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}
	Addition::~Addition()
	{
	}
	double Addition::solve() 
	{
		return m_Num1 + m_Num2;
	}
}