#include <iostream>

// 해결책 1. 생성자에서는 예외 가능성이 있는 작업을 하지 말라!!
//         => 생성자는 "noexcept" 로 만들어라!


struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
	Resource* p;
public:
	// 생성자는 예외 가능성이 없는 작업만 수행합니다.
	// "new Resource" 도 메모리 할당실패시 "std::bad_alloc" 발생합니다.
	Test() : p(nullptr)
	{
		std::cout << "Test()" << std::endl;
	}
	// 객체가 필요한 자원의 할당은 생성자가 아닌
	// 일반 멤버 함수를 사용..!!
	void Construct()
	{
		p = new Resource;
		throw 1;	// 여기서는 예외가 발생해도 생성자가 아니므로
					// 소멸자 호출은 보장됩니다.
	}
	~Test()
	{
		if ( p != nullptr )
			delete p;
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	try
	{
		Test t;			// 객체 생성후
		t.Construct();	// 객체를 초기화..
	}
	catch (...)
	{
		std::cout << "Test 생성자에서 예외 발생" << std::endl;
	}
	std::cout << "프로그램은 계속 실행" << std::endl;
}
