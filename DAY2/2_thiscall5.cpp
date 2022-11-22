#include <iostream>

struct A
{
	int a;
	void fa() { std::cout << "fa : " << this << std::endl; }
};
struct B
{
	int b;
	void fb() { std::cout << "fb : " << this << std::endl; }
};
struct C : public A, public B
{
	int c;
	void fc() { std::cout << "fc : " << this << std::endl; }
};

int main()
{
	C obj;
	obj.fc();	// fc(&obj); // 1000번지라고 가정합니다.

	// 32(64)bit 환경에서 
	// 함수 포인터 : 4(8)바이트 입니다.
	// 멤버 함수 포인터 : 4, 8, 12(8, 16, 24) 일수 있습니다.
	void(C::*f)();

	std::cout << sizeof(f) << std::endl; // 32bit환경에서 8



	f = &C::fa;
//	f = &C::fb;

	(obj.*f)();	// f가 fa 의 주소였다면 1000
				// f가 fb 의 주소였다면 1004 나와야 합니다.
				// => 제대로 동작합니다.
				// => 그런데!!! 어떻게 제대로 동작할수 있을까요 ??
				// => f에 있는 함수가 A 멤버 인지 B멤버인지 알수 없는데 !!

}




