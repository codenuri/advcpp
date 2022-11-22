#include <iostream>
#include <functional>
#include <string>

template<typename T, typename Projection>
const T& mymax(const T& lhs, const T& rhs, Projection proj)
{
	return std::invoke(proj, lhs) < std::invoke(proj, rhs) ? rhs : lhs;
}

struct Point
{
	int x{ 0 };
	int y{ 0 };
};


int main()
{
	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	Point p1 = { 1,1 };
	Point p2 = { 2,2 };

	// mymax 의 3번째 인자를 사용하는 3가지 방법
	// 1. 단항 함수
	// 2. 멤버 함수 주소
	// 3. 멤버 변수 주소

	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });
	
	auto ret2 = mymax(s1, s2, &std::string::size);

	auto ret3 = mymax(p1, p2, &Point::y );
								// 멤버 변수 포인터도 invoke 됩니다.
								// return p1.y < p2.y ? p2 : p1의 의미

	// 현재 버전의 문제점 : 3번째 인자에 디폴트 값이 있어야 합니다.
	auto ret4 = mymax(10, 3); // error. 3번째 인자를 반드시 보내야 하므로
}