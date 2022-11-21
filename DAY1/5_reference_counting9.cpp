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
			// delete �� ���� ����
			// "T*, const T*" ��� ��밡���մϴ�.
			// 
			// delete static_cast<const T*>(this); // ok

			// �׷���, C++ ǥ���� ������ ��ü�� "default_delete"��
			// () �������� ���ڷ� non const �����͸� �����մϴ�.
			D d;
//			d(static_cast<const T*>(this)); // ������ Ÿ���� ()������ȣ��
											// d.operator()() ���	

			d(static_cast<T*>(const_cast<RefCount*>(this))); // ok
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

// Car Ÿ���� ��������� ����
struct Freer
{
	void operator()(void* p) const noexcept
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

class Car : public RefCount< Car, Freer  >
{
};

int main()
{
	Car* p = static_cast<Car*>(malloc(sizeof(Car)));
	new(p) Car; // ������ ȣ���ؾ� refCount �� �ʱ�ȭ �˴ϴ�.
	p->AddRef();
	p->Release();
}


