#include <iostream>
#include <Windows.h>

//===========================================
// C언어의 스레드 개념을 C++ 클래스로 설계해 봅시다.
// 아래 클래스를 라이브러리 내부 클래스라고 가정합니다.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 핵심 1. 아래 멤버 함수를 static 으로 해야 하는 이유를 알아야 합니다.
	//	=> CreateThread()의 3번째 인자는 "일반함수 포인터"로 되어 있으므로
	//    "멤버 함수" 가 아닌 "static 멤버 함수" 이어야 합니다.

	static DWORD __stdcall threadMain(void* p)
	{
//		threadLoop();	// error. 멤버 함수 이므로
						// this->threadLoop()가 되어야 하는데
						// "static 멤버 함수에서는 this 가 없습니다."

		// 인자로 받는 this 포인터를 캐스팅해서 사용하면 모든 멤버 접근이 가능합니다.
		Thread* self = static_cast<Thread*>(p);

		// 이제 self 만 있으면 모든 멤버 접근 가능합니다.
		self->threadLoop();

		return 0;
	}
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