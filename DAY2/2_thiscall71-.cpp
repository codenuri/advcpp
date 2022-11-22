#include <iostream>

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
	*p1 = 20;	

}
