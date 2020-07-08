#pragma once
#ifndef ADDITION_H
#define ADDITION_H

#include "TaschenrechnerV2.h"
#include "Operation.h"

namespace calculator
{
	class Addition : Operation
	{
	public:
		Addition(double pNum1, double pNum2);
		~Addition();
		double solve();
	};
}



#endif 
