#include <iostream>

int main()
{
	int n = 10;

	// 핵심 1. 타입정보 조사하기
	const std::type_info& t1 = typeid(n);
	const std::type_info& t2 = typeid(int);
}