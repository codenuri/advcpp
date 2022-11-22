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
