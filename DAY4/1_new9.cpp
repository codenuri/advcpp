#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. remove 사용.  짝수만 제거
	auto p = std::remove_if(v.begin(), v.end(), 
						[](int n) { return n % 2 == 0; });

	std::cout << v.capacity() << ", " << v.size() << std::endl;

	// 2. erase 사용
	v.erase(p, v.end());

	std::cout << v.capacity() << ", " << v.size() << std::endl;

	// 3. clear() 사용
	v.clear();
	
	std::cout << v.capacity() << ", " << v.size() << std::endl;

	// 4. shrink_to_fit()
	v.shrink_to_fit();

	std::cout << v.capacity() << ", " << v.size() << std::endl;
}
// 위 코드의 각 단계 실행후, capacity 와 size 변화를 생각해보세요.