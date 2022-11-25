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

	// | ������ ������ �Ǿ� �ֽ��ϴ�. "operator |()" ������Դϴ�.
	auto myview = v | std::views::filter([](int n) { return n % 2 == 0; })
					| std::views::take(3);  // take_view(���ǰ��view, 3);

	// �� �ڵ�� �Ʒ��� �����ϴ�.
	std::ranges::filter_view fv(v, [](int n) { return n % 2 == 0; });
	std::ranges::take_view myview2(fv, 3);

	// �ٽ� : range �� ������ �����Դϴ�.
	// => �����Ҷ� ����˴ϴ�.

	v[0] = 100;
	v[2] = 200;

	for (auto e : myview)
	{
		std::cout << e << std::endl; // 2,4,6
	}

}