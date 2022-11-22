#include <iostream>
#include <functional>
#include <string>

template<typename T, typename Projection>
const T& mymax(const T& lhs, const T& rhs, Projection proj)
{
	// 객체를 "Projection" 한 결과를 비교 합니다.
	// 
	// 1. Projection이 일반 단항함수(객체)라면 아래처럼 하면됩니다.
	// return proj(lhs) < proj(rhs) ? rhs : lhs;

	// 2. Projection 멤버 함수 포인터라면 아래처럼 해야 합니다.
	// return (lhs.*proj)() < (rhs.*proj)() ? rhs : lhs;

	// 해결책 : std::invoke 로 호출하면 
	//		=> 일반 함수, 멤버함수 모두 동일하게 호출가능합니다.

	return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;
}


int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });
	auto ret2 = mymax(s1, s2, &std::string::size ); 


	std::cout << ret1 << std::endl; // "AAAAA"
}