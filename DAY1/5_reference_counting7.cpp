#include <iostream>
#include <vector>
#include <atomic>

template<typename T>
class RefCount
{
//	mutable int refCount = 0;
	mutable std::atomic<int> refCount = 0;

public:
	void AddRef() const 
	{
//		++refCount; // refCount.fetch_add(1, std::memory_order_seq_cst)
		refCount.fetch_add(1, std::memory_order_relaxed);
	}

	void Release() const
	{
		if (--refCount == 0)
			delete static_cast<const T*>(this);
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
	const Truck* p = new Truck();

	p->AddRef();
	p->Release();

}


