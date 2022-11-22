// explicit 
#include <iostream>

struct empty1 { empty1() = default; };

struct vector1 
{ 
	vector1(std::size_t size) {} 
};
struct vector2
{
	// explicit 생성자 : 직접 초기화는 가능하고 복사 초기화는 안됨. 
	explicit vector2(std::size_t size) {}
};

void f1(vector1 v) {} // "vector1 v = 10" 의 원리로 받게 됩니다.
void f2(vector2 v) {}

int main()
{	
	// 인자가 int 한개인 생성자가 있으면 아래 처럼 객체 생성 가능합니다.
	vector v1(10);	// 직접 초기화
	vector v1 = 10;	// 복사 초기화.  핵심!

	f1(10); // ok     vector1 는 explicit 아님
	f2(10);	// error. vector2 는 explicit !!
}