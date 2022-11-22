// 39 page
#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� 1. ��� �Լ��� "this" �� �߰� �˴ϴ�.
	void set(int a, int b)  // void set( Point* this, int a, int b)
	{						// {		
		x = a;				//		this->x = 10;	
		y = b;				//		this->y = 10;
	}						// }

	// �ٽ� 2. 
	static void foo(int a)	// void foo(int a)	// this �߰� �ȵ�
	{						// {
		x = a;				//		this->x = a; �� �Ǿ�� �ϴµ� this�������ϴ�
	}						// }				//error!
};

int main()
{
	Point::foo(10); // static ��� �Լ��� ��ü���� ȣ��!!
					// push		10
					// call Point::foo

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) ���� ����˴ϴ�.
					// 32bit �϶�	
					// push		20
					// push		10			���� ���ڴ� �������� ���޵ǰ�
					// mov		ecx, &p1	��ü�ּҸ� ���� �������Ϳ� ������
					// call Point::set()    �Լ��� �̵�

					// 64 ��Ʈ�� ���ڵ� �������� ���
					// mov	r1, 20		// �������ʹ� �ٸ��� ����.	
					// mov  r2, 10
					// mov  rcx, &p1
					// call Point::set()
}



