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

	// ���� 1. ���� 2���� ����
	auto ret1 = mymax(s1, s2);  // s1 < s2 ? s2 : s1


	// ���� 2. �� ��� ���� ( 3��° ���� )
	std::greater<std::string> g;
	auto ret2 = mymax(s1, s2, g);
	auto ret3 = mymax(s1, s2, std::greater<std::string>() ); // �ӽð�ü��

	auto ret4 = mymax(s1, s2, {}); // ����Ʈ Ÿ���� ��ü �����ؼ� ���
								   // ��, std::less<void>{} ��ü ����
									// �� ���� ���� �ʿ�� ����.


}