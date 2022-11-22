#include <iostream>
#include <functional>
#include <string>

template<typename T, typename Projection>
const T& mymax(const T& lhs, const T& rhs, Projection proj)
{
	// ��ü�� "Projection" �� ����� �� �մϴ�.
	// 
	// 1. Projection�� �Ϲ� �����Լ�(��ü)��� �Ʒ�ó�� �ϸ�˴ϴ�.
	// return proj(lhs) < proj(rhs) ? rhs : lhs;

	// 2. Projection ��� �Լ� �����Ͷ�� �Ʒ�ó�� �ؾ� �մϴ�.
	// return (lhs.*proj)() < (rhs.*proj)() ? rhs : lhs;

	// �ذ�å : std::invoke �� ȣ���ϸ� 
	//		=> �Ϲ� �Լ�, ����Լ� ��� �����ϰ� ȣ�Ⱑ���մϴ�.

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