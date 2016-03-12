#include "stdafx.h"
#include "Number.h"


CNumber::CNumber(std::string const & number)
{
	ConvertToArray(number);
}

void CNumber::SetNumber(std::string const & number)
{
	ConvertToArray(number);
}

std::vector<int> CNumber::GetNumber()
{
	return _number;
}

std::string CNumber::SeeNumber()
{
	for (auto digit : _number)
	{
		std::cout << digit;
	}
	std::cout << std::endl;
}


void CNumber::ConvertToArray(std::string const & number)
{
	for(auto digit : number)
	{
		_number.push_back((int)digit);
	}
}
