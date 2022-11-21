#include <iostream>
#include <memory>

// 해결책 2. 자원의 해지는 "자원 관리 객체" 에 의존 하라!!
//  => 스마트 포인터에 의존해라!
//	=> RAII 로 자원을 관리하라!!
//  => 소멸자를 만들지 말라!
//  => "effective-C++" 책의 격언!
// 
//  => 아래 코드에서 "Test() 의 소멸자"는 호출되지 않아도
//     shared_ptr p 의 소멸자는 호출됨을 보장 합니다.

struct Resource
{
	Resource() { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
//	Resource* p;
	std::shared_ptr<Resource> p;

public:
	Test() : p(new Resource)
	{
		std::cout << "Test()" << std::endl;

		throw 1; // 실패 했다고 가정하고 예외 전달
	}

	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...)
	{
		std::cout << "Test 생성자에서 예외 발생" << std::endl;
	}
	std::cout << "프로그램은 계속 실행" << std::endl;
}
