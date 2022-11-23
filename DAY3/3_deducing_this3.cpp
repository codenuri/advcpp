#include <iostream>

/*
template<typename T>
class RefCount
{
public:
	void Release()
	{
//		delete this; // 이렇게 하면 delete RefCount* 타입이되므로 Truck 소멸자
						// 호출 안됨
		delete static_cast<T*>(this);
	}
};

class Truck : public RefCount<Truck>
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
*/

class RefCount
{
public:
	// 기존의 멤버 함수를 객체의 주소를 받을때
	// "무조건 자신의 타입" 으로 전달 받게 됩니다.
//	void Release() // void Release(RefCount* this)
//	{
//		delete this; // 이렇게 하면 delete RefCount* 타입이되므로 Truck 소멸자
//	}

	// explicit Object Parameter 를 사용하면 
	// 정확한 타입으로 받을수 있습니다.
	template<typename T> 
	void Release(this T&& self)  // self 의 타입은 현재 main 코드에서는 Truck 입니다.
	{								
		delete &self;			// 캐스팅없이 delete 가능합니다.
	}							// 즉, CRTP 없어도 됩니다.
};

class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};



int main()
{
	Truck* p1 = new Truck;
	p1->Release(); // 
}