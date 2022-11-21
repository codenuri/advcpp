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

template<typename T, typename D = std::default_delete<T> >
class RefCount : public RefCountBase
{
public:
	void Release() const
	{
		if (--refCount == 0)
		{
			D d;

			d(static_cast<T*>(const_cast<RefCount*>(this))); 
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

int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();

	Truck* p2 = p1;
	p2->AddRef();

	p2->Release();
	p1->Release();
}




