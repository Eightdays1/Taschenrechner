#pragma once
#ifndef DIVISION_H
#define DIVISION_H

#include "TaschenrechnerV2.h"
#include "Operation.h"

namespace calculator
{
	class Division : Operation
	{
	public:
		Division(double pNum1, double pNum2);
		~Division();
		double solve();

	};
}

#endif 
#pragma once
