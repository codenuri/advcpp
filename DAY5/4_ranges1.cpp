#include <vector>
#include <iostream>

// C++20 의 Ranges 라이브러리의 원리에서 사용된 기술들.

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

	// 핵심 1. range for 문이 원리
	for (auto e : v)
	{
		std::cout << e << std::endl;
	}

	// 위 코드를 컴파일러는 아래 처럼 변경합니다.
	auto first = v.begin();
	auto last = v.end();

	for( ; first != last; ++first )
	{
		auto e = *first;
		std::cout << e << std::endl;
	}
}

