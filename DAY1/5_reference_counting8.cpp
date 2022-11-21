#include <iostream>
#include <vector>
#include <atomic>

template<typename T>
class RefCount
{
	mutable std::atomic<int> refCount = 0;
public:
	void AddRef() const { refCount.fetch_add(1, std::memory_order_relaxed);	}

	void Release() const
	{
		if (--refCount == 0)
			delete static_cast<const T*>(this);
	}
	int GetCount() const { return refCount; }
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


