#include <iostream>

// thiscall3.cpp
// 가상함수의 멤버 함수 포인터

class Shape
{
public:
	virtual void Draw() const = 0;	// 순수 가상함수!!
									// 구현이 없습니다.
									// Shape::Draw 함수가 코드메모리에 
									// 있는것아닙니다.
};



class Rect : public Shape
{
public:
	void Draw() const override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() const override { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	// 순수 가상함수(또는 가상함수)의 주소 구하기 
	// => 가상함수 테이블에서 해당 가상함수의 정보가 있는 index 입니다.
	void(Shape::*f)() const = &Shape::Draw;


	// 함수 포인터 f 는 다형성도 지원합니다.
	Rect r;
	(r.*f)();	// "draw Rect"

	Circle c;
	(c.*f)();	// "draw Circle"
		
}
