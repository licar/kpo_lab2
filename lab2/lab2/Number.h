#pragma once
#include <vector>
#include <string>
#include <iostream>

class CNumber
{
public:
	CNumber(std::string const & number);

	std::vector<int> GetNumber();
	void SetNumber(std::string const & number);
	void ConvertToArray(std::string const & number);
	std::string CNumber::SeeNumber();

private:
	std::vector<int> _number;
};

