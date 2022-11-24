#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// 아래 같은 코드가 10곳에 있는데.. 
	// 메모리 할당 방식을 변경하려고 한다면 ?(ex:new 대신 malloc)
//	Point* p1 = new Point(0, 0);
//	delete p1;

	// C++은 메모리 할당 방식을 쉽게 변경하기 위해서 allocator 개념을
	// 제공합니다.
	 
//	std::allocator<Point> ax;	// Point 타입의 메모리 할당기
								// 표준 할당기는 operator new()	
								//				operator delete()사용

	MyAlloc<Point> ax; // 이제, 메모리 할당 방식을 변경하려면
						// 할당기 자체만 변경하면 됩니다.


	Point* p2 = ax.allocate(1); // Point 타입의 메모리 한개 할당

	ax.deallocate(p2, 1);	// 한개 해지!
}



