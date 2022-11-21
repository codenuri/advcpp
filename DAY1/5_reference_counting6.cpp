#include <iostream>
#include <vector>

// �ٽ� : ��ü�� ������ �����ϴ� �Լ�(AddRef, Release) ��
//       => �ݵ�� ��� ��� �Լ� �̾�� �մϴ�.
//		 => ��� ��ü�� ���� ������ �����ؾ� �մϴ�.
//       => AddRef, Release �� ȣ�Ⱑ���ؾ� �Ѵٴ� �ǹ�.

template<typename T>
class RefCount
{
//	int refCount = 0;
	mutable int refCount = 0;	// ��� ����Լ� �ȿ����� ���氡���� ��� ����Ÿ
public:
	void AddRef() const { ++refCount; }

	void Release() const 
	{
		if (--refCount == 0)
			delete static_cast<T*>(this);
	}
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};


class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	// truck ��ü�� �Ӽ��� �б⸸ �Ϸ��� �մϴ�.
	const Truck* p = new Truck();

	p->AddRef();
	p->Release();

}


