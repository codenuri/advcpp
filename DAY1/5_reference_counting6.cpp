#include <iostream>
#include <vector>

// 핵심 : 객체의 수명을 관리하는 함수(AddRef, Release) 는
//       => 반드시 상수 멤버 함수 이어야 합니다.
//		 => 상수 객체도 수명 관리가 가능해야 합니다.
//       => AddRef, Release 를 호출가능해야 한다는 의미.

template<typename T>
class RefCount
{
//	int refCount = 0;
	mutable int refCount = 0;	// 상수 멤버함수 안에서도 변경가능한 멤버 데이타
public:
	void AddRef() const { ++refCount; }

	void Release() const 
	{
		if (--refCount == 0)
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
	// truck 객체의 속성을 읽기만 하려고 합니다.
	const Truck* p = new Truck();

	p->AddRef();
	p->Release();

}


