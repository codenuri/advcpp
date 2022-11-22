#include <iostream>

struct A { int a;};
struct B { int b;};
struct C : public A, public B
{
	int c;
};


int main()
{
	C obj;			// 1000 번지 라면
	A* pA = &obj;	// 1000
//	B* pB = &obj;	// 1004 입니다.
//	B* pB = (B*)&obj;	// 1004 입니다.

//	B* pB = static_cast<B*>(&obj);	// 1004
						// => obj 의 주소에서 "B" 를 찾으라는 것
						// => obj 의 주소와 다른 주소가 반환될수 있습니다.
						// => obj 메모리에 "B"가 없으면 error. 연관성없음.!

	B* pB = reinterpret_cast<B*>(&obj);	// 1000
						// => obj 주소를 B* 로 생각하겠다는것
						// => 항상 같은 주소 반환
						// => obj 와 B는 연관성이 없어도 됩니다.


	std::cout << &obj << std::endl; // 1000
	std::cout << pA << std::endl;	// 1000
	std::cout << pB << std::endl;	// 
}




