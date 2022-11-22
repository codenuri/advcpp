#include <iostream>
#include <Windows.h>

//===========================================
// C����� ������ ������ C++ Ŭ������ ������ ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, 0, 0, 0); }

	DWORD __stdcall threadMain(void* p)
	{
		threadLoop();
		return 0;
	}
	virtual void threadLoop() {}
};


// �Ʒ� Ŭ������ ���̺귯�� ����� Ŭ�����Դϴ�.
class MyThread : public Thread
{
public:
	virtual void threadLoop() { std::cout << "�������۾�" << std::endl; }
};
int main()
{
	MyThread t;
	t.run();	// �̼��� �����尡 �����Ǿ threadLoop �����ؾ� �մϴ�.

	getchar();
}