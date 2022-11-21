#include <iostream>

// SFINAE : Substitution Failure Is Not An Error

// 1. 컴파일시 함수 템플릿을 사용하기로 결정했는데.

// 2. 템플릿에서 실제 함수를 만들다가(인스턴스화) 실패 했다면

// 3. 에러는 아니다.!! <===~~ 핵심!!!

// 4. 동일이름의 다른 함수가 있다면 사용된다.


template<typename T>
//T foo(T a)  { std::cout << "T" << std::endl; return 0; }
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int a) { .... } 모양의 함수를 생성하려고 합니다.

int foo(...) { std::cout << "..." << std::endl; return 0; }


int main()
{
	foo(3); // T 버전 선택
}