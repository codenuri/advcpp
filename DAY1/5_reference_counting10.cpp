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

// 참조계수용 함수를 자동으로 호출하는 스마트 포인터를 만들어 봅시다.
template<typename T>
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }

	AutoPtr(const AutoPtr& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }

	~AutoPtr() { if (obj != nullptr) obj->Release(); }

	// 스마트 포인터의 핵심 : -> 와 *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// 복사 생성자, move 생성자, ->와 * 의 const 버전, 
	// 템플릿 생성자가 필요합니다. - unique_ptr 만들때 설명
};
// webkit 소스에 "AutoPtr.h" 파일 있습니다.

int main()
{
	AutoPtr<Truck> p1 = new Truck;
	AutoPtr<Truck> p2 = p1;

// 	p1->멤버 함수(); // p1은 포인터 처럼사용가능
}

/*
int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();

	Truck* p2 = p1;
	p2->AddRef();

	p2->Release();
	p1->Release();
}




*/