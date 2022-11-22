// checked_delete
#include <iostream>

struct Object;	// 클래스(구조체) 전방 선언(forward declaration)
				// "incomplete type(불안전한 타입)" 이라고 합니다.

//Object obj; // error. 전방선언만 되어 있는 타입의 객체는 생성 안됨.
	  		  //        완전한 선언이 아니므로 size 를 알수 없다.

//Object* p;  // ok. 포인터 선언은 가능. 포인터 변수는 크기가 정해져 있으므로

// 핵심 : incomplete type 을 delete 하면 소멸자가 호출되지 않는다.
void deleter(Object* p)
{
	// 아래 기술을 "checked delete" 라고 합니다.
	static_assert(sizeof(Object) > 0,
							"error, can't delete incomplete type");
	delete p;
}




struct Object
{
	Object()  { std::cout << "Object()" << std::endl; }
	~Object() { std::cout << "~Object()" << std::endl; }
};


int main()
{
	Object* p = new Object();
	deleter(p);
}