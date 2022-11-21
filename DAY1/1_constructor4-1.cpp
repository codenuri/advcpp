#include <iostream>

// �ذ�å 1. �����ڿ����� ���� ���ɼ��� �ִ� �۾��� ���� ����!!
//         => �����ڴ� "noexcept" �� ������!


struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
	Resource* p;
public:
	// �����ڴ� ���� ���ɼ��� ���� �۾��� �����մϴ�.
	// "new Resource" �� �޸� �Ҵ���н� "std::bad_alloc" �߻��մϴ�.
	Test() : p(nullptr)
	{
		std::cout << "Test()" << std::endl;
	}
	// ��ü�� �ʿ��� �ڿ��� �Ҵ��� �����ڰ� �ƴ�
	// �Ϲ� ��� �Լ��� ���..!!
	void Construct()
	{
		p = new Resource;
		throw 1;	// ���⼭�� ���ܰ� �߻��ص� �����ڰ� �ƴϹǷ�
					// �Ҹ��� ȣ���� ����˴ϴ�.
	}
	~Test()
	{
		if ( p != nullptr )
			delete p;
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	try
	{
		Test t;			// ��ü ������
		t.Construct();	// ��ü�� �ʱ�ȭ..
	}
	catch (...)
	{
		std::cout << "Test �����ڿ��� ���� �߻�" << std::endl;
	}
	std::cout << "���α׷��� ��� ����" << std::endl;
}
