#include <iostream>
#include <type_traits>

template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>,
						"error, T is not integer");

	// 최대 공약수를 구하는 함수.
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4); 
}