#include <iostream>
#include <memory>

// 생성자에서 가상함수를 호출하고 싶다면!!!
// => 객체를 생성후에.. 호출하는 방법밖에 없습니다.

struct Base
{
	Base()
	{
//		goo(); // 이 안에서는 가상함수 동작 안합니다.
	}

	template<typename T>
	static std::shared_ptr<T> Create()
	{
		T* p = new T; // 먼저 생성하고
		p->goo();     // 가상함수을 호출(초기화등을 위해서)
		
		return std::shared_ptr<T>(p);
	}


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
// 	Derived d;  // 이렇게 하지 말고

	std::shared_ptr<Derived> sp = Base::Create<Derived>();
	
}
