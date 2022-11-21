#include <iostream>

// 생성자와 예외

// 핵심 1. 생성자에서 작업을 하다가 실패한다면 ??
//       => 생성자는 반환 값을 가질수 없다.
//		 => 일반적으로는 "예외" 를 통해서 실패를 전달한다.

// 핵심 2. 생성자 호출에 성공한 객체만 소멸자가 호출된다.
//      => 생성자에서 예외가 발생하면 소멸자는 호출되지 않는다.
//      => 아래 코드는 생성자에서 자원 할당후 예외가 발생했으므로
//         소멸자가 호출되지 않아서 자원 누수 입니다.

struct Resource
{
	Resource()  { std::cout << "acquire Resource" << std::endl; }
	~Resource() { std::cout << "release Resource" << std::endl; }
};

class Test
{
	Resource* p;
public:
	Test() : p(new Resource)
	{
		std::cout << "Test()" << std::endl;

		throw 1; // 실패 했다고 가정하고 예외 전달
	}

	~Test() 
	{ 
		delete p;
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
