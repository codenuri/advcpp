#include <functional>

class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;						
	void(Dialog::*f2)(int) = &Dialog::Close;	

	Dialog dlg;

	// 핵심 1. 일반 함수 포인터화 멤버 함수 포인터는 사용법이 다릅니다.
	f1(10);
	(dlg.*f2)(10);	

	// 핵심 2. std::invoke 를 사용하면 동일한 표현식으로 사용할수 있습니다.
	// => C++17
	std::invoke(f1, 10);      // 일반함수포인터 사용
	std::invoke(f2, dlg, 10); // 멤버함수포인터 사용


	// 핵심 3. std::mem_fn 을 사용하면 멤버 함수의 주소를 보관했다가
	//  ()로 호출가능합니다. - C++11
	auto f3 = std::mem_fn(&Dialog::Close);

	f3(dlg, 10); 
//	(dlg.*f3)(10); // f3 인 raw pointer 였다면 이렇게 했어야 합니다.

	// 참고 : 멤버 함수의 주소를 구할때는 반드시 &를 붙여야 합니다.
	f1 = foo; // 이렇게해도 되고
	f1 = &foo; // 이 표기도 가능
	f2 = Dialog::Close; // error. & 가 반드시 필요 
	f2 = &Dialog::Close; // ok
}






