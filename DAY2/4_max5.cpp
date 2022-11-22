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


	// �ᱹ �� �ڵ�� s1, s2�� ���� ������ �ʰ�, Projection �� ����� �� �մϴ�.

	// identity �� Projection �� ����� �ᱹ �ڱ� �ڽ� �Դϴ�.
	identity f;
	auto ret2 = mymax(s1, s2, f );
				// f(s1) < f(s2) �ε�, �ᱹ "s1 < s2" 
			
	// ����, identity �� mymax �� 3��° ������ ����Ʈ ������ ä���ϸ� �˴ϴ�.
	auto ret3 = mymax(s1, s2); // ����Ʈ Projection (identity ���)
}