#include <iostream>
#include <any>	// C++17 에서 추가..
				// boost 라이브러리의 초기 부터 있던 도구.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// any : 어떠한 타입의 객체도 보관 가능한 도구

	std::string s = "hello";

	std::any a1 = 10;
	std::any a2 = 3.4;
	std::any a3 = s;

	Point pt(1, 2);
	std::any a4 = pt;

	Point p = std::any_cast<Point>(a4);

	int n = std::any_cast<int>(a4);	// std::bad_any_cast 예외 발생

}

