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
	// �Ʒ� �ڵ� : 2�� ��ü�� Project ����� ������ "<"�� ��
	// return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;

	// 2�� ��ü�� Projection ����� cmp() �� �����ؼ� ��
	// cmp( proj(lhs), proj(rhs) )
//	return cmp( std::invoke(proj, lhs) , std::invoke(proj, rhs) )  ? rhs : lhs;

	// cmp ȣ�� ��ü�� () �����ڰ� �ƴ� std::invoke() �� �ϴ� ���� �����ϴ�.
	
	return std::invoke(cmp,			// cmp �Լ���
					  std::invoke(proj, lhs), std::invoke(proj, rhs))  //2������
										? rhs : lhs;
}

int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	// �Ʒ� �ڵ�� ��ü 2��(s1, s2) �� Projection ����� "<" �� �� ���մϴ�.
//	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });

	std::greater<int> g; // 2�� ��ҿ� ���ؼ� ">" ������ �ϴ� �Լ� ��ü

	auto ret1 = mymax(s1, s2, g, [](const std::string& s) { return s.size(); });
		// => s1, s2�� Projection �����
		// => 3��° ���ڷ� ������ ���� �����ڸ� ���ؼ� ��
		


}