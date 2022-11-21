#include <iostream>
#include <vector>

class Car
{	
	int speed;
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();	// 규칙 1. 객체를 생성하면 참조계수 증가

	Car* p2 = p1;
	p2->AddRef();	// 규칙 2. 객체의 포인터를 복사하면 참조계수 증가

	p2->Release();
	std::cout << "----------" << std::endl;
	p1->Release(); // 규칙 3. 객체를 사용후 에는 참조계수 감소
}


