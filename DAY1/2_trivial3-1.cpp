#include <iostream>

// 핵심 1. trivial 여부를 조사하는 traits 는 C++11 이후에 표준에 추가됩니다.
// => 그런데, 사용자가 만드는 방법이 없습니다.
// => 컴파일러가 지원해야 합니다.

// 1. "모든 생성자는 trivial 하지 않다"
template <typename T> struct trait_trivial_ctor { enum { value = false }; };

// 2. 각 타입을 만드는 사람이 trivial 여부를 알려주어야 합니다.
struct Point
{
	int x, y;
};
template<> struct trait_trivial_ctor<Point>
{
	enum { value = true  };
};

int main()
{
	std::cout << trait_trivial_ctor<Point>::value << std::endl;
}



