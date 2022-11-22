// explicit 
#include <iostream>

struct empty1 { empty1() = default; };

struct vector1 
{ 
	vector1(std::size_t size) {} 
};
struct vector2
{
	// explicit ������ : ���� �ʱ�ȭ�� �����ϰ� ���� �ʱ�ȭ�� �ȵ�. 
	explicit vector2(std::size_t size) {}
};

void f1(vector1 v) {} // "vector1 v = 10" �� ������ �ް� �˴ϴ�.
void f2(vector2 v) {}

int main()
{	
	// ���ڰ� int �Ѱ��� �����ڰ� ������ �Ʒ� ó�� ��ü ���� �����մϴ�.
	vector v1(10);	// ���� �ʱ�ȭ
	vector v1 = 10;	// ���� �ʱ�ȭ.  �ٽ�!

	f1(10); // ok     vector1 �� explicit �ƴ�
	f2(10);	// error. vector2 �� explicit !!
}