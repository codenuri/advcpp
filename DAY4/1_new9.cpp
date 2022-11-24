#include <vector>
#include <iostream>
#include <algorithm>
#include "debug_alloc.h"

int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	std::vector<int, debug_alloc<int> > v = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. remove 사용.  짝수만 제거
	auto p = std::remove_if(v.begin(), v.end(), 
						[](int n) { return n % 2 == 0; });

	std::cout << v.capacity() << ", " << v.size() << std::endl;

	// 2. erase 사용
	// => 메모리 제거가 아닌, 객체의 파괴(소멸자 호출)
	v.erase(p, v.end());
	std::cout << v.capacity() << ", " << v.size() << std::endl; // 10, 5


	// 3. clear() 사용
	// => 모든 요소 객체의 파괴, 단, 메모리는 파괴 안됨.
	v.clear();	
	std::cout << v.capacity() << ", " << v.size() << std::endl; // 10, 0


	// 4. shrink_to_fit()
	// => capacity 를 size 크기로 해달라!
	// => 현재 size == 0 이므로 메모리 제거!
	v.shrink_to_fit();

	std::cout << v.capacity() << ", " << v.size() << std::endl; // 0, 0
}


// 위 코드의 각 단계 실행후, capacity 와 size 변화를 생각해보세요.