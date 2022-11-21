#include <iostream>

// 생성자와 가상함수
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
