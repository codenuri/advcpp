#include <iostream>
#include <type_traits>

// 아래 리턴 타입을 잘 생각해 보세요

// std::enable_if<조건, T>::type 이 최종 결과는
// 조건이 참일때   : T
// 조건이 거짓일때 : error. "::type" 이 없다.
//				=> SFINAE 에 따라서 "::type" 이 없어도 에러가 아니라
//				=> 함수 생성만 안함.
//				=> 따라서, gcd(double, double) 버전 사용가능


template<typename T> 
typename std::enable_if< std::is_integral_v<T>, T>::type 
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