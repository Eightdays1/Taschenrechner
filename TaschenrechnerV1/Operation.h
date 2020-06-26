#pragma once
#ifndef OPERATION_H
#define OPERATION_H

//#include "TaschenrechnerV1.h"

namespace calculator
{
	class Operation
	{
	public:
		Operation(double pNum1, double pNum2);	//Konstruktor
		Operation();
		~Operation();							//Destruktor

		//define methods
		virtual double solve();

	protected:

		//define Variables
		double m_Num1;
		double m_Num2;
	};

}

#endif