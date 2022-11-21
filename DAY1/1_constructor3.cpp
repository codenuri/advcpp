#include <iostream>

// 생성자와 가상함수

// 핵심 1. 생성자에서는 "가상함수"가 동작하지 않습니다.
//        => 객체에 상관없이 무조건 자신의 멤버 함수가 호출된다는 의미.
//        => 만약, 가상함수가 정상 동작했다면
//           아래 코드의 Derived::goo() 에서 x 사용시, 초기화되지 않은 x 를사용
//											하게 됩니다.!

struct Base
{
	Base()     { goo(); } // 생성자에서는 가상함수가 동작하지 않습니다.
						  // 항상 "Base::goo" 입니다.

	void foo() { goo(); } // 객체에 따라 달라짐
						  // Derived 객체라면 "Derived::goo()"
	virtual void goo() { std::cout << "Base::goo" << std::endl; }
};
struct Derived : public Base
{
	int x;
	Derived() : x(10) {}

	virtual void goo() override { std::cout << "Derived::goo" << std::endl; }
};
int main()
{
	Derived d;
//	d.foo();
}
