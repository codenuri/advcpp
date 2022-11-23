#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	// p를 5칸 전진하고 싶다.
//	p = p + 5;	// vector 반복자(임의접근 반복자)만 + 가 가능합니다.
				// list 반복자(양방향 반복자)는 +은 안되고
				// ++만 가능합니다.

//	++p; ++p; ++p; ++p; ++p; // 모든 종류의 반복자에 사용가능

	std::advance(p, 5); // p 가 임의접근이면 +로 이동
						// p 가 임의접근이 아니면 ++로 이동


	std::cout << *p << std::endl; 
}
