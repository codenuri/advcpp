#include <vector>
#include <iostream>
#include <ranges> 

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9 };

	// C++20/23 에 이미 많은 다양한 view 가 있습니다.
	std::ranges::reverse_view rv(v);
	std::ranges::take_view tv(rv, 3); // 중첩도 됩니다.

	using namespace std::ranges;

//	for (auto e : tv)
	for (auto e : take_view(reverse_view(v), 3) )
	{
		std::cout << e << std::endl;
	}

	// | 연산자 재정의 되어 있습니다. "operator |()" 만든것입니다.
	auto myview = v | std::views::filter([](int n) { return n % 2 == 0; })
					| std::views::take(3);  // take_view(앞의결과view, 3);

	// 위 코드는 아래와 같습니다.
	std::ranges::filter_view fv(v, [](int n) { return n % 2 == 0; });
	std::ranges::take_view myview2(fv, 3);

	// 핵심 : range 는 지연된 실행입니다.
	// => 열거할때 적용됩니다.

	v[0] = 100;
	v[2] = 200;

	for (auto e : myview)
	{
		std::cout << e << std::endl; // 2,4,6
	}

}