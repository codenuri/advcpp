#include <iostream>
#include <functional>

struct Point
{
	int x;
	int y;
};

void f1(int   n)  {}
void f2(Point pt) {}

// f3 �� ���� �Լ� ��ü�� �ްڴٴ°� �Դϴ�
template<typename T = std::less<void> > // C++14 �� ����
void f3(T func)
{
	bool b = func(1, 2);
}

int main()
{
	int n1 = 0;
	int n2 = {}; // ���� �����մϴ�. 0���� �ʱ�ȭ �˴ϴ�.
	Point pt = {}; // ����Ʈ ������ ����ϰڴٴ� ��

	f1({});
	f2({});

	f3(std::less<int>());
	f3(std::greater<int>());
	f3({}); // std::less<void> �� �ӽð�ü�� �����ϴ� ǥ����� �˴ϴ�.
}