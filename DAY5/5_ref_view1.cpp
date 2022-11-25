#include <vector>
#include <ranges>
#include <iostream>

int main()
{
	std::vector v1 = { 1, 2, 3 };
	std::vector v2 = { 5, 6, 7, 8, 9 };

	std::vector<int>& r1 = v1;
	std::vector<int>& r2 = v2;

//	r1 = r2; // 이 코드의 실행 결과는 ?
		// => 이코드는 참조의 이동이 아닌 vector의 복사 입니다.
		// => r2가 가리키던 vector를 r1이 가리키던 vector로 복사

	std::cout << v1.size() << std::endl; // 5
	std::cout << v2.size() << std::endl; // 5
	std::cout << r1.size() << std::endl; // 5
	std::cout << r2.size() << std::endl; // 5


	// 참조는 이동될수 없지만
	// 포인터는 이동될수 있습니다.
	std::vector<int>* p1 = &v1;
	std::vector<int>* p2 = &v2;

	p1 = p2; // vector 의 복사가 아닌 포인터의 이동

	std::cout << v1.size() << std::endl;	// 3
	std::cout << p1->size() << std::endl;	// 5

}
