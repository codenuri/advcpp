#include <iostream>
#include <functional>
#include <string>

struct identity
{
	template<typename T>
	constexpr T&& operator()(T&& obj) const noexcept
	{
		return std::forward<T>(obj);
	}
};

template<typename T,
	typename Projection = identity,
	typename Comp = std::less<void> >
const T& mymax(const T& lhs, const T& rhs,
	Comp cmp = {},
	Projection proj = {})
{
	return std::invoke(cmp, std::invoke(proj, lhs), std::invoke(proj, rhs)) ? rhs : lhs;
}

int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	// 사용법 1. 인자 2개만 전달
	auto ret1 = mymax(s1, s2);  // s1 < s2 ? s2 : s1


	// 사용법 2. 비교 방식 변경 ( 3번째 인자 )
	std::greater<std::string> g;
	auto ret2 = mymax(s1, s2, g);
	auto ret3 = mymax(s1, s2, std::greater<std::string>() ); // 임시객체로

	auto ret4 = mymax(s1, s2, {}); // 디폴트 타입의 객체 생성해서 사용
								   // 즉, std::less<void>{} 객체 생성
									// 이 경우는 보낼 필요는 없음.


}