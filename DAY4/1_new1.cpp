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
	// new �� �ϴ� ��
	// 1. �޸� �Ҵ� - operator new() �Լ� ���
	// 2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	// delete �� �ϴ� ��
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ���� - operator delete() �Լ� ���
//	delete p1;


	Point* p = operator new( sizeof(Point) );

	operator delete(p);
}