#include <iostream>
#include <vector>
#include <atomic>

// template 을 만들때
// 1. 타입인자 T를 사용하지 않은 멤버 함수(멤버데이타)가 있다면
// 2. 템플릿이 아닌 기반 클래스를 만들어서 제공하자.

// "Thin Template" 또는 "template hoisting" 이라는 불리는 기술입니다.
class RefCountBase
{
protected:
	mutable std::atomic<int> refCount = 0;

public:
	void AddRef() const { refCount.fetch_add(1, std::memory_order_relaxed);	}
	int GetCount() const { return refCount; }

protected:
	~RefCountBase() {}
};

template<typename T> class RefCount : public RefCountBase
{	
public:
	void Release() const
	{
		if (--refCount == 0)
			delete static_cast<const T*>(this);
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


