#include <iostream>
#include <string>
#include <optional>

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
	std::optional<int> op1(10);

	std::optional<int> op2(std::nullopt);

	std::optional<Point> op3(Point(1, 2));
						// => 초기값으로 임시객체를 전달하는 코드
						// => 비효율적

//	std::optional<Point> op4(1, 2);
						// => 내부적으로 Point 보관할때 1,2 로 생성해서
						//    보관하라는 의미.
						// => 생성자가 여러개있는데..
						//    이렇게 하면 한개이상의 생성자와 매칭되어서
						//   ambiguous 에러!

	std::optional<Point> op4( std::in_place, 1, 2);
						// std::in_place 는 생성자를 선택하기 위해 만든
						// empty 입니다.
						// 어제 배운 
						// class zero_and_arg{} 의 개념
}

