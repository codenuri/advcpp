class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) {} 

int main()
{
	// 핵심 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없습니다.
	//         일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.
	void(*f1)(int) = &foo;				// ok. 		
	void(*f2)(int) = &Dialog::Close;	// error. 멤버함수는 this추가됨
	void(*f2)(int) = &Dialog::Close2;	// ok. 
}






