#include <iostream>
#include <functional>

struct Point
{
	int x;
	int y;
};

void f1(int   n)  {}
void f2(Point pt) {}

// f3 은 이항 함수 객체를 받겠다는것 입니다
template<typename T = std::less<void> > // C++14 도 가능
void f3(T func)
{
	bool b = func(1, 2);
}

int main()
{
	int n1 = 0;
	int n2 = {}; // 위와 동일합니다. 0으로 초기화 됩니다.
	Point pt = {}; // 디폴트 생성자 사용하겠다는 것

	f1({});
	f2({});

	f3(std::less<int>());
	f3(std::greater<int>());
	f3({}); // std::less<void> 의 임시객체를 전달하는 표기법이 됩니다.
}