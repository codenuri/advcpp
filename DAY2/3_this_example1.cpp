#include <iostream>
#include <Windows.h>

// �ٽ� : CreateThread �� ���޵Ǵ� �Լ��� �ݵ�� ���ڰ� void* �Ѱ��̾��
//        �մϴ�.
DWORD __stdcall foo(void* p)
{
	std::cout << "foo" << std::endl;
	return 0;
}

int main()
{
	// windows OS ���� "������ ����� C �Լ�" 
	CreateThread(0, 0, foo, "A", 0, 0); 										
	getchar();
}