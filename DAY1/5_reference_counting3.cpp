#include <iostream>
#include <vector>

class Car
{
	int speed;
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	// protected 소멸자
	// 1. 외부에서 delete 를 할수 없다.
	// 2. 스택에 객체를 만들수 없다.
protected:
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();

	// 1. 사용자가 실수로 delete 한다면 ?
	delete p1;

	// 2. 객체를 스택에 만든 다면
	Car c1;


	p1->Release(); 
}


