#include <iostream>
#include <vector>

// ������� ����� �����ϴ� ��� Ŭ����
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()	// void Release( RefCount* this)
	{
		if (--refCount == 0) 
			delete this; // ��, �̼��� this �� Ÿ���� RefCount* �Դϴ�.
						// �Ҹ��ڰ� ������ �ƴϸ� "~RefCount()" �� ȣ��
						// �Ҹ��ڰ� �����̾�� ���� ��ü�� ������ ȣ��
	}
protected:
//	~RefCount() { std::cout << "~RefCount" << std::endl; }
	virtual ~RefCount() { std::cout << "~RefCount" << std::endl; }
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


