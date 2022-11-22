// 39 page
#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 1. 멤버 함수는 "this" 가 추가 됩니다.
	void set(int a, int b)  // void set( Point* this, int a, int b)
	{						// {		
		x = a;				//		this->x = 10;	
		y = b;				//		this->y = 10;
	}						// }

	// 핵심 2. 
	static void foo(int a)	// void foo(int a)	// this 추가 안됨
	{						// {
		x = a;				//		this->x = a; 가 되어야 하는데 this가없습니다
	}						// }				//error!
};

int main()
{
	Point::foo(10); // static 멤버 함수는 객체없이 호출!!
					// push		10
					// call Point::foo

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) 으로 변경됩니다.
					// 32bit 일때	
					// push		20
					// push		10			실제 인자는 스택으로 전달되고
					// mov		ecx, &p1	객체주소를 보통 레지스터에 담은후
					// call Point::set()    함수로 이동

					// 64 비트는 인자도 레지스터 사용
					// mov	r1, 20		// 레지스터는 다를수 있음.	
					// mov  r2, 10
					// mov  rcx, &p1
					// call Point::set()
}



