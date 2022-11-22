#include <iostream>
#include <Windows.h>

// 핵심 : CreateThread 에 전달되는 함수는 반드시 인자가 void* 한개이어야
//        합니다.
DWORD __stdcall foo(void* p)
{
	std::cout << "foo" << std::endl;
	return 0;
}

int main()
{
	// windows OS 에서 "스레드 만드는 C 함수" 
	CreateThread(0, 0, foo, "A", 0, 0); 										
	getchar();
}