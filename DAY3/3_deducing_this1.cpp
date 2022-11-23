#include <iostream>

// deducing this pattern 개념 - C++23 의 1번째로 꼽는 기술입니다.
// => "explicit object parameter" 가 공식 명칭입니다.

class Object
{
	int x = 0;
public:
	void f1(int a)	// void f1(Object* this, int a) 로 컴파일 됩니다.
	{
	}

	// 아래 함수는 f1과 동일한 의미 입니다.
	// => 컴파일러가 this를 추가하는 것이 아니라, 사용자가 직접 인자로 받는 코드
	// => vs2022 에서 "C++ latest" 버전으로 컴파일하면 됩니다.
	// => g++ 은 -std=c++23 이 필요한데, 아직 지원 안됩니다.
	void f2(this Object& self, int a)
	{
		// 멤버 데이타 접근하기
//		x = a; // error

		self.x = a;// ok

	}
};

int main()
{
	Object obj;
	obj.f1(10);		// f1(&obj, 10) 즉, 객체의 주소가 멤버 함수로 전달
	obj.f2(10);
}