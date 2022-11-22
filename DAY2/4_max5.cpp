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

template<typename T, typename Projection>
const T& mymax(const T& lhs, const T& rhs, Projection proj)
{
	return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;
}

int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });

}