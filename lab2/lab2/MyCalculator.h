#pragma once
#include "Calculator.h"


class CMyCalculator
{
public:
	static CLongInt operator+(CLongInt const & left, CLongInt const & right);
	static CLongInt operator*(CLongInt const & left, CLongInt const & right);
	static CLongInt operator-(CLongInt const & left, CLongInt const & right);
private:
	static bool CheckIsLeftMore(std::vector<int> const &left, std::vector<int> const &right);
};

