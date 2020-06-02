#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>

using namespace std;

class Memory
{
public:
	Memory(String input, double result);			//Konstruktor
	~Memory();										//Destruktor

	string getInput();
	double getResult();

private:
	double numberresult;
	string input;
};

#endif // !NUMBER_H