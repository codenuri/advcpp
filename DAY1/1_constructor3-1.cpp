#include <iostream>
#include <memory>

// �����ڿ��� �����Լ��� ȣ���ϰ� �ʹٸ�!!!
// => ��ü�� �����Ŀ�.. ȣ���ϴ� ����ۿ� �����ϴ�.

struct Base
{
	Base()
	{
//		goo(); // �� �ȿ����� �����Լ� ���� ���մϴ�.
	}

	template<typename T>
	static std::shared_ptr<T> Create()
	{
		T* p = new T; // ���� �����ϰ�
		p->goo();     // �����Լ��� ȣ��(�ʱ�ȭ���� ���ؼ�)
		
		return std::shared_ptr<T>(p);
	}


	virtual void goo() { std::cout << "Base::goo" << std::endl; }
};


struct Derived : public Base
{
	int x;
	Derived() : x(10) {}

	virtual void goo() override { std::cout << "Derived::goo" << std::endl; }
};
int main()
{
// 	Derived d;  // �̷��� ���� ����

	std::shared_ptr<Derived> sp = Base::Create<Derived>();
	
}
