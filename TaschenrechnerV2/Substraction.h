#pragma once
#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "TaschenrechnerV2.h"
#include "Operation.h"

namespace calculator
{
	class Substraction : Operation
	{
	public:
		Substraction(double pNum1, double pNum2);
		~Substraction();
		double solve();

	};
}

#endif 
