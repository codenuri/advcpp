#include <iostream>
#include <Windows.h>

DWORD __stdcall foo(void* p)
{
	std::cout << "foo" << std::endl;
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);
	getchar();
}
//===========================================
// C언어의 스레드 개념을 C++ 클래스로 설계해 봅시다.
// 아래 클래스를 라이브러리 내부 클래스라고 가정합니다.
class Thread
{
public:
	void run() {}

	virtual void threadLoop() {}
};
// 아래 클래스는 라이브러리 사용자 클래스입니다.
class MyThread : public Thread
{
public:
	virtual void threadLoop() { std::cout << "스레드작업" << std::endl; }
};
int main()
{
	MyThread t;
	t.run();	// 이순간 스레드가 생성되어서 threadLoop 수행해야 합니다.

	getchar();
}