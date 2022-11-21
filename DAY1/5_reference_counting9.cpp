#include <iostream>
#include <vector>
#include <atomic>

class RefCountBase
{
protected:
	mutable std::atomic<int> refCount = 0;

public:
	void AddRef() const { refCount.fetch_add(1, std::memory_order_relaxed); }
	int GetCount() const { return refCount; }

protected:
	~RefCountBase() {}
};

// ��ü�� �����ϴ� ����� �����Ҽ� �ֵ���
// std::default_delete<T> : C++ ǥ���� �޸� ������ �Լ� ��ü
//							���������� () �����ڿ��� "delete" ����
template<typename T, typename D = std::default_delete<T> > 
class RefCount : public RefCountBase
{
public:
	void Release() const
	{
		if (--refCount == 0)
		{
			//	delete static_cast<const T*>(this);
			D d;
			d(static_cast<const T*>(this)); // ������ Ÿ���� ()������ȣ��
								// d.operator()() ���
		}
	}

protected:
	~RefCount() { }
};


class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
class Car : public RefCount< Car  >
{
};





int main()
{
	const Truck* p = new Truck();

	p->AddRef();
	p->Release();

}


