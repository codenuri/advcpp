#include <iostream>
#include <any>	// C++17 ���� �߰�..
// boost ���̺귯���� �ʱ� ���� �ִ� ����.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	std::string s = "hello";

	any a1 = 10;
	any a2 = 3.4;
	any a3 = s;

	Point pt(1, 2);
	any a4 = pt;

//	Point p = any_cast<Point>(a4);
}

