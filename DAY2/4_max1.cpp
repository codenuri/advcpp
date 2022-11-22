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
	
	std::cout << ret2 << std::endl;  // 5 입니다.
									// "AAAAA" 가 나오게 할수 없을까요?


	// 핵심 2. 비교의 기준을 변경 가능하게 싶습니다.
	// 다음중 좋은 방법을 선택해 보세요

	// 방법1. 이항 조건자 - C++98 시절의 STL 스타일
	mymax(s1, s2,
		[](std::string& a, std::string& b) { return a.size() < b.size(); });


	// 방법 2. 단항 조건자 사용 - Python 스타일
	mymax(s1, s2, [](std::string& s) { return a.size(); } );

}