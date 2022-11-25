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
	// any : ��� Ÿ���� ��ü�� ���� ������ ����

	std::string s = "hello";

	std::any a1 = 10;
	std::any a2 = 3.4;
	std::any a3 = s;

	Point pt(1, 2);
	std::any a4 = pt;

	Point p = std::any_cast<Point>(a4);

	int n = std::any_cast<int>(a4);	// std::bad_any_cast ���� �߻�

}

