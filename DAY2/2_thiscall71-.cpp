#include <iostream>

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
	*p1 = 20;	

}
