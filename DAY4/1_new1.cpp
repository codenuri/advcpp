#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point()						 { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// new 가 하는 일
	// 1. 메모리 할당 - operator new() 함수 사용
	// 2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	// delete 가 하는 일
	// 1. 소멸자 호출
	// 2. 메모리 해지 - operator delete() 함수 사용
//	delete p1;


	Point* p = operator new( sizeof(Point) );

	operator delete(p);
}