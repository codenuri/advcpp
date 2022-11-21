#include <iostream>

// 핵심 : foo 함수가 아래 처럼 3개일때, "foo(3)" 이 함수 찾는 순서
//       
//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }


int main()
{
	foo(3);		// 1. int - exactly matching
				// 2. T - template 을 사용해서 int 버전 생성
				// 3. ... 
}