#include <iostream>
#include <vector>

// 참조계수 기능을 제공하는 기반 클래스

template<typename T>
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()	
	{
		if (--refCount == 0)
			//	delete this;	// 문제점 : this 의 타입이 "RefCount*" 라는 점
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
	Truck* p = new Truck();
	p->AddRef();
	p->Release();

}


