#include <iostream>
#include <any>	// C++17 에서 추가..
// boost 라이브러리의 초기 부터 있던 도구.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

struct any
{
	void* data;

	const std::type_info& (*get_type)(); // 함수 포인터입니다.

	void(*deleter)(void*);	// 보관하던 객체를 파괴하기 위한 함수 포인터

	template<typename T>
	any(const T& value) : data( new T(value) )
	{
		get_type = []() -> const std::type_info& { return typeid(T); };

		deleter = [](void* data) { delete static_cast<T*>(data); };
	} 

	~any() { deleter( data ); }
};

int main()
{
	Point pt(1, 2);
	any a1 = pt;

	std::cout << a1.get_type().name() << std::endl;


//	Point p = any_cast<Point>(a1);
}

