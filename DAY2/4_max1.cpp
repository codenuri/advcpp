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
	int ret = mymax(10, 3);	// 3

	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2);	
	std::cout << ret1 << std::endl; // "BBB"

	
	// 핵심 1. 알파벳 순서가 아닌 문자열의 길이를 기준으로 큰 문자열을
	//        구하고 싶다.
	auto ret2 = mymax(s1.size(), s2.size());
	
	std::cout << ret2 << std::endl;  // ??

}