#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. remove 사용.  짝수만 제거
	auto p = std::remove_if(v.begin(), v.end(), 
						[](int n) { return n % 2 == 0; });

	// 2. erase 사용
	v.erase(p, v.end());

	// 3. clear() 사용
	v.clear();
	
	// 4. shrink_to_fit()
	v.shrink_to_fit();
}
