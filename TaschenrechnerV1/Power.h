#pragma once
#ifndef POWER_H
#define POWER_H

#include "TaschenrechnerV1.h"
#include "Operation.h"

namespace calculator
{
	class Power : Operation
	{
	public:
		Power(double pNum1, double pNum2);
		~Power();
		double solve();
	};
}



#endif 
