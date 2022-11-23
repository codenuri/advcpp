#include <iostream>

/*
template<typename T>
class RefCount
{
public:
	void Release()
	{
//		delete this; // �̷��� �ϸ� delete RefCount* Ÿ���̵ǹǷ� Truck �Ҹ���
						// ȣ�� �ȵ�
		delete static_cast<T*>(this);
	}
};

class Truck : public RefCount<Truck>
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
*/

class RefCount
{
public:
	// ������ ��� �Լ��� ��ü�� �ּҸ� ������
	// "������ �ڽ��� Ÿ��" ���� ���� �ް� �˴ϴ�.
//	void Release() // void Release(RefCount* this)
//	{
//		delete this; // �̷��� �ϸ� delete RefCount* Ÿ���̵ǹǷ� Truck �Ҹ���
//	}

	// explicit Object Parameter �� ����ϸ� 
	// ��Ȯ�� Ÿ������ ������ �ֽ��ϴ�.
	template<typename T> 
	void Release(this T&& self)  // self �� Ÿ���� ���� main �ڵ忡���� Truck �Դϴ�.
	{								
		delete &self;			// ĳ���þ��� delete �����մϴ�.
	}							// ��, CRTP ��� �˴ϴ�.
};

class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};



int main()
{
	Truck* p1 = new Truck;
	p1->Release(); // 
}