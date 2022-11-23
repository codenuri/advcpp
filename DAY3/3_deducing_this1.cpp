#include <iostream>

// deducing this pattern ���� - C++23 �� 1��°�� �Ŵ� ����Դϴ�.
// => "explicit object parameter" �� ���� ��Ī�Դϴ�.

class Object
{
	int x = 0;
public:
	void f1(int a)	// void f1(Object* this, int a) �� ������ �˴ϴ�.
	{
	}

	// �Ʒ� �Լ��� f1�� ������ �ǹ� �Դϴ�.
	// => �����Ϸ��� this�� �߰��ϴ� ���� �ƴ϶�, ����ڰ� ���� ���ڷ� �޴� �ڵ�
	// => vs2022 ���� "C++ latest" �������� �������ϸ� �˴ϴ�.
	// => g++ �� -std=c++23 �� �ʿ��ѵ�, ���� ���� �ȵ˴ϴ�.
	void f2(this Object& self, int a)
	{
		// ��� ����Ÿ �����ϱ�
//		x = a; // error

		self.x = a;// ok

	}
};

int main()
{
	Object obj;
	obj.f1(10);		// f1(&obj, 10) ��, ��ü�� �ּҰ� ��� �Լ��� ����
	obj.f2(10);
}