#include <iostream>

int main()
{
	int n = 10;

	// 핵심 1. 타입정보 조사하기
	// => std::type_info 는 복사 될수 없습니다. const & 로만 받아야 합니다.
	const std::type_info& t1 = typeid(n);	// typeid(변수)
	const std::type_info& t2 = typeid(int);	// typeid(타입)

	// type_info 는 == 연산 가능합니다.
	if (t1 == t2) {}	// 결국, 이코드는 "n 이 int 인가 조사" 하는것

	std::cout << t1.name() << std::endl;
}