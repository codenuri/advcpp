#include <iostream>

// 핵심 1. 생성자 호출원리 
//     2. 생성자 호출 순서는 변경할수 없다. 
//        => 기반 클래스 생성자가, 멤버의 생성자 보다 먼저 호출된다.

struct BM	// Base Member
{
	BM()  { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};
struct DM	// Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;

	// 사용자 코드	// 컴파일러가 변경한 코드
	Base()			// Base() : bm()
	{
		std::cout << "Base()" << std::endl; 
	}
	~Base() 
	{
		std::cout << "~Base()" << std::endl; 
		
		// BM::~bm() 의 코드를 컴파일러가 추가.
	}
};

struct Derived : public Base
{
	DM dm;
	// 사용자 코드	// 컴파일러 변경 코드
//	Derived()		// Derived() : Base(), dm()
	Derived() : dm(), Base()	// <= 이렇게 표기해도, 호출순서는 Base()
								//   가 먼저 실행됩니다.
	{
		std::cout << "Derived()" << std::endl; 
	}
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 

		// DM::~dm()
		// Base::~Base()
	}
};
int main()
{
	// 아래 한줄이 실행될때 생성자가 호출되는 순서!
	Derived d;	// 여기서는 "call Derived::Derived()" 만 호출!
}
