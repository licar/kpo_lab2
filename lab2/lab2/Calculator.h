#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class CLongInt
{
public:
	CLongInt(std::string const & number);
	CLongInt(std::vector<int> const & number);
	std::vector<int> GetNumber() const;
	void SetNumber(std::string const & number);
	void SetNumber(std::vector<int> const & longInt);

	std::string SeeResult() const;

private:
	std::vector<int> _number;
	std::vector<int> ConvertToArray(std::string const & number) const;
	std::vector<int> ToValidView(std::vector<int> const & number) const;
};

CLongInt operator+(CLongInt const & left, CLongInt const & right);
CLongInt operator-(CLongInt const & left, CLongInt const & right);
CLongInt operator*(CLongInt const & left, CLongInt const & right);
CLongInt operator/(CLongInt const & left, CLongInt const & right);

bool CheckIsLeftMore(std::vector<int> const & left, std::vector<int> const & right);
std::vector<double> DefineShare(std::vector<int> const & right);