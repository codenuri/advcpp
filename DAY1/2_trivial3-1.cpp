#include <iostream>

// �ٽ� 1. trivial ���θ� �����ϴ� traits �� C++11 ���Ŀ� ǥ�ؿ� �߰��˴ϴ�.
// => �׷���, ����ڰ� ����� ����� �����ϴ�.
// => �����Ϸ��� �����ؾ� �մϴ�.

// 1. "��� �����ڴ� trivial ���� �ʴ�"
template <typename T> struct trait_trivial_ctor { enum { value = false }; };

// 2. �� Ÿ���� ����� ����� trivial ���θ� �˷��־�� �մϴ�.
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



