// 1_new10
#include <vector>
#include <iostream>

int main()
{
	// 핵심 1. 크기를 지정하는 것과 용량(capacity)를 확보하는 것의 차이점
	std::vector<int> v1(1000); // 1000 개 메모리 할당 + 생성자 호출
								// capacity=1000, size=1000
	std::vector<int> v2;
	v2.reserve(1000);	// 1000개 메모리만 할당
						// capacity = 1000, size = 0

	v2.push_back(10);	// 이순간 사용자 타입이면 생성자 호출
						// size=1
	//----------------------------------------------
	// 핵심 2. 복사 생성자의 동작 방식
	std::vector<int> v3(10, 0);
	v3.resize(7);

	std::vector<int> v4 = v3;

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // ?
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; // ?
}