#include <iostream>
#include <functional>
#include <string>
#include <algorithm>// 이 안에 있는 std::ranges::max 가 우리가 만든것과
					// 유사합니다.
					// 큰 차이가 한개 있는데.. 내일 설명
					// mymax            : 함수  
					// std::ranges::max : 함수객체
int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = std::ranges::max(s1, s2);

	std::greater<std::string> g;
	auto ret2 = std::ranges::max(s1, s2, g);
	auto ret3 = std::ranges::max(s1, s2, std::greater<std::string>());
	auto ret4 = std::ranges::max(s1, s2, std::greater<void>());
	auto ret5 = std::ranges::max(s1, s2, {});	
	auto ret6 = std::ranges::max(s1, s2, {}, &std::string::size);
	auto ret7 = std::ranges::max(s1, s2, {}, [](auto& s) { return s.size(); });
}
