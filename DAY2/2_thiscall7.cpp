#include <iostream>

// 멤버 변수 포인터
struct Point
{
	int x{ 0 };
	int y{ 0 };
};

int main()
{
	int n = 0;
	int* p1 = &n;	// 일반 변수의 주소

//	int* p2 = &Point::y; // error


	// 핵심 1. 멤버 데이타의 포인터 만들기.
	// => "현재 Point 타입의 객체가 없다" 는 점을 유의하세요!!
	int Point::*p2 = &Point::y; // 멤버 데이타의 주소!!

	// 핵심 2. 멤버 데이타의 포인터의 의미
	// => 해당 멤버가 객체의 시작부터 얼마나 떨어져 있는가 ?

	printf("%d\n", p2); // 4

	std::cout << p2 << std::endl;	// 이렇게 하지마세요
									// "1" 입니다.
}
