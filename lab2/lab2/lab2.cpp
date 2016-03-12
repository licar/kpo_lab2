// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Calculator.h"
#include <iostream>

int main()
{
	CLongInt left = CLongInt("19405863");
	CLongInt right = CLongInt("19405863");
	CLongInt resultSum =  left + right;
	std::cout << resultSum.SeeResult() << std::endl;
	
	CLongInt resultMul = left * right;
	std::cout << resultMul.SeeResult() << std::endl;

	CLongInt resultDif = left - right;
	std::cout << resultDif.SeeResult() << std::endl;

	CLongInt resultDiv = left / right;
	std::cout << resultDiv.SeeResult() << std::endl;
	return 0;
}

