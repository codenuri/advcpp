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


	// 1. 생성자 호출없이 메모리만 할당 ( malloc 와 유사 )
	Point* p = static_cast<Point*>( operator new( sizeof(Point) ));


	// 2. 이미 할당된 메모리에 대해서 생성자만 호출
//	new(p) Point(0, 0);		// "placement new" 라고 합니다.
							// "위치지정 new"
	
	std::construct_at(p, 0, 0); // C++20 부터 지원
				// => 내부적으로는 다시 "new(p) Point(0,0)" 하고 있습니다


	// 3. 메모리 해지 없이 소멸자만 호출
//	p->~Point();		// C++98 스타일
	std::destroy_at(p); // C++17 부터는 이렇게 해도 됩니다.


	// 4. 소멸자 없이 메모리 해지( free 와 유사 )
	operator delete(p);
}

// malloc vs new
// malloc : 메모리의 할당
// new    : 객체의 생성 ( 메모리를 할당 + 생성자 호출 )

// new Point(0,0)       : 새로운 메모리에 객체를 생성해 달라
// new(주소) Point(0,0) : 이미 할당된 메모리 에 객체를 생성해달라


