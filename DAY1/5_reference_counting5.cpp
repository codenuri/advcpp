#include <iostream>
#include <vector>

// CRTP 기술
// => Curiously Recurring Template Pattern 
// => 기반 클래스가 템플릿 인데, 템플릿 인자로 파생 클래스이름을 전달
//    하는 기술
// => CRTP 는 아주 다양한 활용이 가능한데..
// => 아래 코드는 가상 소멸자를 사용하지 않기 위해서 사용




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


