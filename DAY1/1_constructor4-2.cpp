#include <iostream>
#include <memory>

// �ذ�å 2. �ڿ��� ������ "�ڿ� ���� ��ü" �� ���� �϶�!!
//  => ����Ʈ �����Ϳ� �����ض�!
//	=> RAII �� �ڿ��� �����϶�!!
//  => �Ҹ��ڸ� ������ ����!
//  => "effective-C++" å�� �ݾ�!
// 
//  => �Ʒ� �ڵ忡�� "Test() �� �Ҹ���"�� ȣ����� �ʾƵ�
//     shared_ptr p �� �Ҹ��ڴ� ȣ����� ���� �մϴ�.

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
//	Resource* p;
	std::shared_ptr<Resource> p;

public:
	Test() : p(new Resource)
	{
		std::cout << "Test()" << std::endl;

		throw 1; // ���� �ߴٰ� �����ϰ� ���� ����
	}

	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...)
	{
		std::cout << "Test �����ڿ��� ���� �߻�" << std::endl;
	}
	std::cout << "���α׷��� ��� ����" << std::endl;
}
