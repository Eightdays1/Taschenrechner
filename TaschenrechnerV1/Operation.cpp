#include "Operation.h"


namespace calculator
{
	Operation::Operation(double pNum1, double pNum2)
	{
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}

	Operation::Operation()
	{
	}

	Operation::~Operation()
	{

	}
	double Operation::solve()
	{
		return 0.0;
	}
}

