#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을 지원 합니다.
void foo(int)    {}
void foo(double) {}

// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면 좋지 않을까요 ?
//void goo(가상함수가있는클래스들) {}
//void goo(가상함수가없는클래스들) {}


// enable_if 를 사용한 반환 타입만드는 기술
// => 반환 타입 자리에 아래 코드 적으세요
// 
// std::enable_if_t< 조건, "반환타입"> 
// => 단, 반환 타입이 void 라면 생략도 가능

template<typename T> 
std::enable_if_t< std::is_polymorphic_v<T> > 
goo(T a)
{
	std::cout << "has virtual function" << std::endl;
}
template<typename T> 
std::enable_if_t< ! std::is_polymorphic_v<T> >
goo(T a)
{
	std::cout << "no virtual function" << std::endl;
}

class AA { virtual void foo() {} };

int main()
{
	int n = 10;
	goo(n);	// 가상함수가 없는 타입 입니다.
	AA aa;
	goo(aa);
}


