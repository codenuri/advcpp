#include <vector>
#include <iostream>

// C++20 �� Ranges ���̺귯���� �������� ���� �����.

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

	// �ٽ� 1. range for ���� ����
	for (auto e : v)
	{
		std::cout << e << std::endl;
	}

	// �� �ڵ带 �����Ϸ��� �Ʒ� ó�� �����մϴ�.
	auto first = v.begin();
	auto last = v.end();

	for( ; first != last; ++first )
	{
		auto e = *first;
		std::cout << e << std::endl;
	}
}

