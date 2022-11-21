#include <iostream>

// trivial(자명하다)
// => special member function 이 하는 일이 널리 알려진 대로 동작!
// => 컴파일러의 기본 제공 버전을 사용하는 가 ?

// 생성자, 소멸자 : 아무 일도 하지 않을때 trivial
// 복사 생성자    : 모든 멤버를 얕은 복사할때 trivial

class A
{
};

class B
{
public:
	virtual void foo() {}
};
int main()
{

}
