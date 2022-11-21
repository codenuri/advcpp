#include <iostream>
#include <type_traits>

// static_assert : 조건을 만족하지 못하면 "컴파일 에러"
// 조건을 만족하지 못하면 에러가 아니라
// 1. 후보에서 제외 할수 없을까 ?
// 2. 제외되면 동일이름의 다른 함수가 호출될수 있다.

template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>,
						"error, T is not integer");

	// 최대 공약수를 구하는 함수.
	return 0;
}
double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4); 

	gcd(3.1f, 5.4f);
}