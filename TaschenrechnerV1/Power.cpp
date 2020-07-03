#include "Power.h"
#include <math.h>

namespace calculator {

	Power::Power(double pNum1, double pNum2) {
		m_Num1 = pNum1;
		m_Num2 = pNum2;
	}

	Power::~Power()
	{
	}

	double Power::solve()
	{
		return pow(m_Num1, m_Num2);
	}

}