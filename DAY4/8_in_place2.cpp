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
						// => �ʱⰪ���� �ӽð�ü�� �����ϴ� �ڵ�
						// => ��ȿ����

//	std::optional<Point> op4(1, 2);
						// => ���������� Point �����Ҷ� 1,2 �� �����ؼ�
						//    �����϶�� �ǹ�.
						// => �����ڰ� �������ִµ�..
						//    �̷��� �ϸ� �Ѱ��̻��� �����ڿ� ��Ī�Ǿ
						//   ambiguous ����!

	std::optional<Point> op4( std::in_place, 1, 2);
						// std::in_place �� �����ڸ� �����ϱ� ���� ����
						// empty �Դϴ�.
						// ���� ��� 
						// class zero_and_arg{} �� ����
}

