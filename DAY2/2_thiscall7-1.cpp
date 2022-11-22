#include <iostream>
#include <functional>
// ��� ���� ������
struct Point
{
	int x{ 0 };
	int y{ 0 };
};

int main()
{
	int Point::*p1 = &Point::y; 

	// �ٽ� 1. "pointer to member data" ����ϱ�
//	*p1 = 20;	// error. ��ü�� ����.

	Point pt;
	
	pt.*p1 = 20;	 // ok.  pt.y = 20 �� ����
					 // => *(int*)((char*)&pt + p1) = 20;

	(&pt)->*p1 = 20; // ok


	// �ٽ� 2. ��� "����Ÿ" �����͵� std::invoke �����մϴ�.
	
	int n = std::invoke(p1, pt); // pt.*p1

	std::invoke(p1, pt) = 30;	// pt.*p1 = 30

	std::cout << pt.y << std::endl;
}
