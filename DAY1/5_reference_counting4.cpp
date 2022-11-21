#include <iostream>
#include <vector>

// 참조계수 기능을 제공하는 기반 클래스
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()	// void Release( RefCount* this)
	{
		if (--refCount == 0) 
			delete this; // 즉, 이순간 this 의 타입은 RefCount* 입니다.
						// 소멸자가 가상이 아니면 "~RefCount()" 만 호출
						// 소멸자가 가상이어야 실제 객체를 조사후 호출
	}
protected:
//	~RefCount() { std::cout << "~RefCount" << std::endl; }
	virtual ~RefCount() { std::cout << "~RefCount" << std::endl; }
};


// Truck 도 참조 계수로 관리하고 싶다.
class Truck : public RefCount
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


