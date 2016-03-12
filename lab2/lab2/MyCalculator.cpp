#include "stdafx.h"
#include "MyCalculator.h"

CLongInt CMyCalculator::operator+(CLongInt const & left, CLongInt const & right)
{
	std::vector<int> result;
	std::vector<int> leftOp = left.GetNumber();
	std::vector<int> rightOp = right.GetNumber();

	std::reverse(leftOp.begin(), leftOp.end());
	std::reverse(rightOp.begin(), rightOp.end());

	if (leftOp.size() < rightOp.size())
	{
		size_t size = rightOp.size() - leftOp.size();
		for (size_t i = 0; i != size; ++i)
		{
			leftOp.push_back(0);
		}
	}
	else if (leftOp.size() > rightOp.size())
	{
		size_t size = leftOp.size() - rightOp.size();
		for (size_t i = 0; i != size; ++i)
		{
			rightOp.push_back(0);
		}
	}

	result.resize(1);
	for (size_t i = 0; i != leftOp.size(); ++i)
	{
		int sum = leftOp[i] + rightOp[i] + result[i];
		int units = sum % 10;
		int dozens = sum / 10;

		result[i] = units;

		if (dozens > 0)
		{
			result.push_back(dozens);
		}
		else
		{
			if (i != leftOp.size() - 1)
			{
				result.push_back(dozens);
			}
		}
	}

	std::reverse(result.begin(), result.end());
	return CLongInt(result);
}

CLongInt CMyCalculator::operator*(CLongInt const & left, CLongInt const & right)
{
	std::vector<int> result;
	std::vector<int> leftOp = left.GetNumber();
	std::vector<int> rightOp = right.GetNumber();

	std::reverse(leftOp.begin(), leftOp.end());
	std::reverse(rightOp.begin(), rightOp.end());

	result.resize(std::max(leftOp.size(), rightOp.size()) * 3);
	for (size_t j = 0; j != rightOp.size(); ++j)
	{
		for (size_t i = 0; i != leftOp.size(); ++i)
		{
			int mult = (leftOp[i] * rightOp[j]) + result[i + j] + (result[i + j + 1] * 10);
			int units = mult % 10;
			int dozens = mult / 10;
			int hundreds = mult / 100;

			result[i + j] = units;
			result[i + j + 1] = dozens;
		}
	}

	std::vector<int> resultWithoutZeros;
	bool endedZeros = false;

	std::reverse(result.begin(), result.end());

	return CLongInt(result);
}

CLongInt CMyCalculator::operator-(CLongInt const & left, CLongInt const & right)
{
	std::vector<int> leftOp = left.GetNumber();
	std::vector<int> rightOp = right.GetNumber();


	std::reverse(leftOp.begin(), leftOp.end());
	std::reverse(rightOp.begin(), rightOp.end());

	if (CheckIsLeftMore(leftOp, rightOp))
	{
		return CLongInt("999999999999999999999999999999999999999");
	}

	if (leftOp.size() > rightOp.size())
	{
		size_t size = leftOp.size() - rightOp.size();
		for (size_t i = 0; i != size; ++i)
		{
			rightOp.push_back(0);
		}
	}

	for (size_t i = 0; i != leftOp.size(); ++i)
	{
		int minus = leftOp[i] - rightOp[i];

		if (minus < 0)
		{
			leftOp[i] = 10 - std::abs(minus);
			bool isEndDecrease = false;
			for (size_t j = i + 1; !isEndDecrease; ++j)
			{
				int decreasedNumber = leftOp[j] - 1;

				if (decreasedNumber >= 0)
				{
					leftOp[j] = decreasedNumber;
					isEndDecrease = true;
				}
				else
				{
					leftOp[j] = 10 - std::abs(decreasedNumber);
				}
			}
		}
		else
		{
			leftOp[i] = minus;
		}
	}

	std::reverse(leftOp.begin(), leftOp.end());
	return CLongInt(leftOp);
}

bool CMyCalculator::CheckIsLeftMore(std::vector<int> const &left, std::vector<int> const &right)  
{
	if (left.size() < right.size())
	{
		return false;
	}
	else if (left.size() == right.size())
	{
		for (size_t i = 0; i != left.size(); ++i)
		{
			if (right[i] < left[i])
			{
				break;
			}
			else if (right[i] > left[i])
			{
				return false;
			}
		}
	}
	return true;
}