// 1_new10
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v1(1000); // 1000 개 메모리 할당 + 생성자 호출

	std::vector<int> v2;
	v2.reserve(1000);	// 1000개 메모리만 할당
						// capacity = 1000, size = 0

}