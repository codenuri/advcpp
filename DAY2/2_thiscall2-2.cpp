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

}






