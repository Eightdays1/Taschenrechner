#pragma once
#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "TaschenrechnerV1.h"
#include "Operation.h"

namespace calculator
{
	class Multiplication : Operation
	{
	public:
		Multiplication(double pNum1, double pNum2);
		~Multiplication();
		double solve();

	};
}

#endif 
