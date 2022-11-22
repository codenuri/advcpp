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
	// 아래 코드 : 2개 객체의 Project 결과를 무조건 "<"로 비교
	// return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;

	// 2개 객체의 Projection 결과를 cmp() 에 전달해서 비교
	// cmp( proj(lhs), proj(rhs) )
//	return cmp( std::invoke(proj, lhs) , std::invoke(proj, rhs) )  ? rhs : lhs;

	// cmp 호출 자체를 () 연산자가 아닌 std::invoke() 로 하는 것이 좋습니다.
	
	return std::invoke(cmp,			// cmp 함수에
					  std::invoke(proj, lhs), std::invoke(proj, rhs))  //2개전달
										? rhs : lhs;
}

int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	// 아래 코드는 객체 2개(s1, s2) 의 Projection 결과를 "<" 로 만 비교합니다.
//	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });

	std::greater<int> g; // 2개 요소에 대해서 ">" 연산을 하는 함수 객체

	auto ret1 = mymax(s1, s2, g, [](const std::string& s) { return s.size(); });
		// => s1, s2의 Projection 결과를
		// => 3번째 인자로 전달한 이항 조건자를 통해서 비교
		


}