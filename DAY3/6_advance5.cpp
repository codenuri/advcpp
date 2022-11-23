#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++17 까지 : 반복자 설계자가 자신이 어떤 종류의 반복자인지
//				알려주어야 합니다.

// C++20 부터 : 알려주지 않아도 조사 가능합니다.
//			   => C++20 concept
//			   => haskell 이 메타 클래스 개념
//			   => rust 의 "traits" 개념

// 임의접근 반복자가 가져야 하는 특징을 "정의" 합니다.
// => 개념의 정의 라고 합니다.
template<typename T>
concept random_access_iterator = requires(T& p)
{
	++p;
	p++;
	--p;
	p--;
	p + 1;
	*p;
};

template<typename T> void check(T& p)
{
	// bool b = 컨셉이름<타입>; // 타입이 컨셉을 만족하는지 조사
	std::cout << random_access_iterator<T> << std::endl;
}
int main()
{
	int n = 10;
	int* p = &n;

	check(n); // int
	check(p); // int*
}