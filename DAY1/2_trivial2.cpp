#include <iostream>
#include <type_traits>

class Test
{
public:
//	virtual void foo() {}	// 이 멤버 때문에 생성자는 trivial 아닙니다.
	
//	void goo() {}	// 일반 멤버 함수가 있어도 생성자 trivial
//	int value;		// 객체형 멤버가 아니면 생성자 trivial

//	int data = 0;	// 필드 초기화는 결국 
					// 생성자의 초기화리스트에서 동작하는 코드입니다.

//	Test() {}  // 사용자가 생성자의 구현을 제공하면 trivial 하지 않습니다.

	Test() = default; // 컴파일러에게 요청. 
					  // 생성자는 trivial
};


int main()
{
	// 생성자의 trivial 여부를 조사하는 방법

	bool b1 = std::is_trivially_default_constructible<Test>::value; // C++11
	bool b2 = std::is_trivially_default_constructible_v<Test>;		// C++17

	std::cout << b2 << std::endl;
}
