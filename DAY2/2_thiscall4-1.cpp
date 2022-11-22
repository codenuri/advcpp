// 2_thiscall4-1 - 5�� ����
#include <iostream>

struct A
{
	int a;
	void fa() { std::cout << "fa : " << this << std::endl; }
};
struct B
{
	int b;
	void fb() { std::cout << "fb : " << this << std::endl; }
};
struct C : public A, public B
{
	int c;
	void fc() { std::cout << "fc : " << this << std::endl; }
};
int main()
{
	C obj;

	std::cout << &obj << std::endl; // 1000 ���� �϶� �Ʒ� 3�� �����ϼ���

	// �Ʒ� 3���� �����  ��µǴ� �ּ� ������ ������
	obj.fa();	// fa  1000
				// => fa(&obj)   ok!!

	obj.fb();	// fb  1004
				// => fb(&obj) ??? ó���Ǹ� �ȵȴ�!!
				// => fb(&obj + sizeof(A));

	obj.fc();	// fc  1000

}




