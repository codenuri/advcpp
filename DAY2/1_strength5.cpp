// const member function
#include <iostream>
#include <set>

class Point
{
	int x{ 0 }, y{ 0 };
public:
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}

//	bool operator<(const Point& pt)			// Ʋ�� �ڵ�!!!
	bool operator<(const Point& pt) const	// �´� �ڵ�!!
	{
		return x < pt.x;
	}
};

// set �ȿ����� �Ʒ��� ���� "��� ���� ����"�� ���� ���ڸ� ���ϰԵ˴ϴ�.
void insert(const Point& root, const Point& newelem)
{
	if (root < newelem) // root.operator<(newelem) �� ����ε�
	{					// root �� ��� ��ü�̹Ƿ�
						// "operator<()" �� �ݵ�� ��� ����Լ��̾���մϴ�
	}
}

int main()
{
	// ����� ���� Ÿ���� set �� �����ϱ� ����
	// 1. �񱳸� �ϴ� �Լ� ��ü�� �����ϰų�
	// 2. Ÿ�� ��ü�� "<" ������ �����ؾ� �մϴ�.
	std::set<Point> s;

	s.emplace(1, 2); // error.  s.insert( Point(1,2) )
}
