#include <iostream>
#include <type_traits>

template<typename T>
//typename std::enable_if< std::is_integral_v<T>, T>::type // C++11
std::enable_if_t< std::is_integral_v<T>, T>       // C++17 Ç¥±â¹ý
gcd(T a, T b)
{
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
	gcd(3.1, 5.4);

	gcd(3.1f, 5.4f);
}