#include <iostream>
#include <functional>
#include <string>
#include <algorithm>// �� �ȿ� �ִ� std::ranges::max �� �츮�� ����Ͱ�
					// �����մϴ�.
					// ū ���̰� �Ѱ� �ִµ�.. ���� ����
					// mymax            : �Լ�  
					// std::ranges::max : �Լ���ü
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
