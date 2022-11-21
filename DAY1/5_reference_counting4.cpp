#include <iostream>
#include <vector>

// ������� ����� �����ϴ� ��� Ŭ����
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};
// Truck �� ���� ����� �����ϰ� �ʹ�.
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


