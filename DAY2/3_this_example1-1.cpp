#include <iostream>
#include <Windows.h>

//===========================================
// C����� ������ ������ C++ Ŭ������ ������ ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// �ٽ� 1. �Ʒ� ��� �Լ��� static ���� �ؾ� �ϴ� ������ �˾ƾ� �մϴ�.
	//	=> CreateThread()�� 3��° ���ڴ� "�Ϲ��Լ� ������"�� �Ǿ� �����Ƿ�
	//    "��� �Լ�" �� �ƴ� "static ��� �Լ�" �̾�� �մϴ�.

	static DWORD __stdcall threadMain(void* p)
	{
//		threadLoop();	// error. ��� �Լ� �̹Ƿ�
						// this->threadLoop()�� �Ǿ�� �ϴµ�
						// "static ��� �Լ������� this �� �����ϴ�."

		// ���ڷ� �޴� this �����͸� ĳ�����ؼ� ����ϸ� ��� ��� ������ �����մϴ�.
		Thread* self = static_cast<Thread*>(p);

		// ���� self �� ������ ��� ��� ���� �����մϴ�.
		self->threadLoop();

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