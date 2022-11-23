#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), std::less<int>()); // C++98 스타일

	// 아래 코드는 모두 같은 의미 입니다.
	std::sort(v.begin(), v.end(), std::less<void>()); // C++14 스타일
	std::sort(v.begin(), v.end(), std::less<>());
	std::sort(v.begin(), v.end(), std::less()); // C++17
	std::sort(v.begin(), v.end(), std::less{}); //
	std::sort(v.begin(), v.end(), {}); 
}



