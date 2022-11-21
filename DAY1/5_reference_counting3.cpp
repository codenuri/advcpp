#include <iostream>
#include <vector>

class Car
{
	int speed;
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	// protected �Ҹ���
	// 1. �ܺο��� delete �� �Ҽ� ����.
	// 2. ���ÿ� ��ü�� ����� ����.
protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();

	// 1. ����ڰ� �Ǽ��� delete �Ѵٸ� ?
	delete p1;

	// 2. ��ü�� ���ÿ� ���� �ٸ�
	Car c1;


	p1->Release(); 
}


