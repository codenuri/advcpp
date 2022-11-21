#include <iostream>
#include <vector>

// 참조계수 기능을 제공하는 기반 클래스
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};
// Truck 도 참조 계수로 관리하고 싶다.
class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
int main()
{
	Truck* p = new Truck();
	p->AddRef();
	p->Release();

}


