class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) {}

int main()
{
	// 핵심 1. 멤버 함수의주소를 담으려면 멤버 함수 포인터를 사용해야합니다
	void(*f1)(int) = &foo;						// 일반함수 포인터
	void(Dialog::*f2)(int) = &Dialog::Close;	// 멤버 함수 포인터

	// 핵심 2. 멤버 함수 포인터 사용하기
	f1(10); // ok. 일반 함수 포인터!
//	f2(10); // error. 멤버 함수는 객체가 있어야 호출가능합니다.!!

	Dialog dlg;
//	dlg.f2(10);	// error. Dialog 안에는 "f2" 라는 멤버는 없다.!


	// Pointer To member 라는 연산자를 사용해야 합니다.(".*", "->*" )
	dlg.*f2(10);	// error. 연산자 우선순위 문제 
					//		  .* 보다 () 가 빠릅니다.

	(dlg.*f2)(10);	// ok.. 이 표기법이 멤버 함수 포인터를 사용해서
					//		멤버 함수를 호출하는 표기법입니다.

	// .* 와 ->* 사용하기
	Dialog* pdlg = &dlg;
	(dlg.*f2)(10);
	(pdlg->*f2)(10);	
}






