#include <iostream>
#include <functional>
// 멤버 변수 포인터
struct Point
{
	int x{ 0 };
	int y{ 0 };
};

int main()
{
	int Point::*p1 = &Point::y; 

	// 핵심 1. "pointer to member data" 사용하기
//	*p1 = 20;	// error. 객체가 없다.

	Point pt;
	
	pt.*p1 = 20;	 // ok.  pt.y = 20 과 동일
					 // => *(int*)((char*)&pt + p1) = 20;

	(&pt)->*p1 = 20; // ok


	// 핵심 2. 멤버 "데이타" 포인터도 std::invoke 가능합니다.
	
	int n = std::invoke(p1, pt); // pt.*p1

	std::invoke(p1, pt) = 30;	// pt.*p1 = 30

	std::cout << pt.y << std::endl;
}

// 함수 객체(function object)
// => () 연산자를 사용해서 호출 가능한 모든 객체
// => 함수, 함수포인터, 멤버 함수, 멤버함수 포인터,
//    ()연산자를 재정의한 클래스의 객체, 람다 표현식등

// Callable Object ( 호출가능한 객체 ) <= 이 용어가 더 중요합니다.
// => std::invoke() 가 가능한 객체
// => function object + 멤버데이타 포인터

