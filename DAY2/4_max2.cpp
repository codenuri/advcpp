#include <iostream>
#include <functional>
#include <string>

template<typename T>
const T& mymax(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2, 
					[](const std::string& s) { return s.size(); });

	std::cout << ret1 << std::endl; // "AAAAA"
}