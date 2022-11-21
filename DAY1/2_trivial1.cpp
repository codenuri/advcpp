#include <iostream>

// trivial(자명하다)
// => special member function 이 하는 일이 널리 알려진 대로 동작!
// => 컴파일러의 기본 제공 버전을 사용하는 가 ?

// 생성자, 소멸자 : 아무 일도 하지 않을때 trivial
// 복사 생성자    : 모든 멤버를 얕은 복사할때 trivial

class A
{
};

class B //: public A
{
//	A a;
public:
//	virtual void foo() {}
};
// 생성자의 trivial 조건
// 1. 가상함수가 없고
// 2. 기반 클래스가 없거나 기반 클래스의 생성자가 trivial 하고
// 3. 객체형 멤버가 없거나 객체형 멤버의 생성자가 trivial 하고
// 4. 사용자가 만든 생성자가 없을때

// 생성자는 "trivial" 합니다.



int main()
{
	B* p = (B*)malloc(sizeof(B)); // malloc 은 생성자 호출 안됨

	// 생성자 호출없이 객체 사용
//	p->foo();

	// 이미 할당된 메모리에 생성자만 호출
	new(p) B;

	// 생성자 호출후 사용
	p->foo();
}
