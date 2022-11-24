#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// 힙에 Point 한개를 만들려면 아래 처럼 하면 됩니다.
	Point* p1 = new Point(0, 0);

	// 힙에 Point 10개를 연속으로 만들어 보세요 ??
//	Point* p2 = new Point[10]; // error. 이렇게 하면 디폴트 생성자가 필요합니다.


	// C++11 부터는 아래 처럼 할수는 있습니다.
	// => 10개의 객체가 Point(int, int) 생성자 사용
	Point* p2 = new Point[10]{ {0,0}, {0,0},{0,0}, {0,0}, {0,0},
								{0,0}, {0,0},{0,0}, {0,0}, {0,0} };

	// 메모리 할당과 생성자 호출을 분리하면 
	// 객체의 생성을 보다 유연하게 할수 있습니다.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 이미 할당된 메모리에 10개의 객체를 생성(생성자 호출을 의미)
	for (int i = 0; i < 10; i++)
	{
		new(&p3[i]) Point(0, 0);
	}

	// 객체를 파괴
	for (int i = 0; i < 10; i++)
		p3[i].~Point();


	operator delete(p3);

}




