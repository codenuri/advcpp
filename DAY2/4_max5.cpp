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

template<typename T, typename Projection = identity>
const T& mymax(const T& lhs, const T& rhs, Projection proj = {} )
{
	return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;
}

int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });


	// 결국 위 코드는 s1, s2를 직접 비교하지 않고, Projection 된 결과를 비교 합니다.

	// identity 는 Projection 의 결과가 결국 자기 자신 입니다.
	identity f;
	auto ret2 = mymax(s1, s2, f );
				// f(s1) < f(s2) 인데, 결국 "s1 < s2" 
			
	// 따라서, identity 를 mymax 의 3번째 인자의 디폴트 값으로 채택하면 됩니다.
	auto ret3 = mymax(s1, s2); // 디폴트 Projection (identity 사용)
}