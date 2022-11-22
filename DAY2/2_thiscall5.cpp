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

	void(C::*f)(); // => { 함수 주소 보관 공간, this offset 보관 공간    }


	std::cout << sizeof(f) << std::endl; // 32bit환경에서 8


//	f = &C::fa;  // f = { &fa 주소, 0 }
	f = &C::fb;  // f = { &fb 주소, sizeof(A) }


	(obj.*f)();	// f가 fa 의 주소였다면 1000
				// f가 fb 의 주소였다면 1004 나와야 합니다.
				// => 제대로 동작합니다.
				// => 그런데!!! 어떻게 제대로 동작할수 있을까요 ??
				// => f에 있는 함수가 A 멤버 인지 B멤버인지 알수 없는데 !!

				// 원리 : f.보관된함수주소(&obj + f.this_offset);

	// 결론 : 32bit 환경이라면
	// 모든 포인터는 4바이트 이다!!! 라고 생각할수 있지만
	// 멤버 함수의 포인터는 4바이트 가 아닐수도 있습니다.
	// => 다중상속사용시 8바이트
	// => 가상상속사용시 일부 컴파일러는 12바이트
	
	// 그래서 void* 에 멤버 함수 포인터를 담을수 없습니다.
	void* p = &Obj::fa; // error

}




