// const member function
#include <iostream>
#include <set>

class Point
{
	int x{ 0 }, y{ 0 };
public:
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}

//	bool operator<(const Point& pt)			// 틀린 코드!!!
	bool operator<(const Point& pt) const	// 맞는 코드!!
	{
		return x < pt.x;
	}
};

// set 안에서는 아래와 같이 "상수 참조 형태"로 받은 인자를 비교하게됩니다.
void insert(const Point& root, const Point& newelem)
{
	if (root < newelem) // root.operator<(newelem) 의 모양인데
	{					// root 는 상수 객체이므로
						// "operator<()" 는 반드시 상수 멤버함수이어야합니다
	}
}

int main()
{
	// 사용자 정의 타입을 set 에 저장하기 위해
	// 1. 비교를 하는 함수 객체를 전달하거나
	// 2. 타입 자체가 "<" 연산이 가능해야 합니다.
	std::set<Point> s;

	s.emplace(1, 2); // error.  s.insert( Point(1,2) )
}
