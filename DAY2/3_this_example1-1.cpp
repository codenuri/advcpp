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
// C����� ������ ������ C++ Ŭ������ ������ ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.
class Thread
{
public:
	void run() {}

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