#include <vector>
#include <iostream>
#include <ranges> 

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9 };

	// C++20/23 �� �̹� ���� �پ��� view �� �ֽ��ϴ�.
	std::ranges::reverse_view rv(v);
	std::ranges::take_view tv(rv, 3); // ��ø�� �˴ϴ�.

	using namespace std::ranges;

//	for (auto e : tv)
	for (auto e : take_view(reverse_view(v), 3) )
	{
		std::cout << e << std::endl;
	}

	// | ������ ������ �Ǿ� �ֽ��ϴ�

	auto myview = v | std::views::filter([](int n) { return n % 2 == 0; })
					| std::views::take(3);  // take_view(���ǰ��view, 3);


}