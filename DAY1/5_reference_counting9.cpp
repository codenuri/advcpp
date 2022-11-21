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

// 객체를 삭제하는 방법을 변경할수 있도록
// std::default_delete<T> : C++ 표준의 메모리 삭제자 함수 객체
//							내부적으로 () 연산자에서 "delete" 수행
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
			d(static_cast<const T*>(this)); // 삭제자 타입의 ()연산자호출
								// d.operator()() 사용
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


