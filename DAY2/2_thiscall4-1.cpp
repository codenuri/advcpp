// 2_thiscall4-1 - 5번 복사
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

	std::cout << &obj << std::endl; // 1000 번지 일때 아래 3줄 예측하세요

	// 아래 3줄의 결과로  출력되는 주소 예측해 보세요
	obj.fa();	// fa  1000
				// => fa(&obj)   ok!!

	obj.fb();	// fb  1004
				// => fb(&obj) ??? 처럼되면 안된다!!
				// => fb(&obj + sizeof(A));

	obj.fc();	// fc  1000

}




