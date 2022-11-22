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

	// mymax �� 3��° ���ڸ� ����ϴ� 3���� ���
	// 1. ���� �Լ�
	// 2. ��� �Լ� �ּ�
	// 3. ��� ���� �ּ�

	auto ret1 = mymax(s1, s2, [](const std::string& s) { return s.size(); });
	
	auto ret2 = mymax(s1, s2, &std::string::size);

	auto ret3 = mymax(p1, p2, &Point::y );
								// ��� ���� �����͵� invoke �˴ϴ�.
								// return p1.y < p2.y ? p2 : p1�� �ǹ�

	// ���� ������ ������ : 3��° ���ڿ� ����Ʈ ���� �־�� �մϴ�.
	auto ret4 = mymax(10, 3); // error. 3��° ���ڸ� �ݵ�� ������ �ϹǷ�
}