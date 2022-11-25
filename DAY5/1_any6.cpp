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

	const std::type_info& (*get_type)();
	void(*deleter)(void*);

	template<typename T>
	any(const T& value)
		: data(new T(value)),
		get_type([]() -> const std::type_info& { return typeid(T); }),
		deleter([](void* data) { delete static_cast<T*>(data); })
	{
	}

	~any() { deleter(data); }
};

template<typename T>
T any_cast(any& a)
{
	if (typeid(T) != a.get_type())
		throw std::bad_any_cast();

	return *(static_cast<T*>(a.data));
}

int main()
{
	Point pt(1, 2);

	any a1(pt);
//	any a2(1,2);	// 이렇게 할수 없을까 ?
					// Point 라는 타입에 대한 정보가 없습니다.

	// 참고
	// 함수 템플릿은 명시적으로 타입전달 가능합니다.
	obj.foo<Point>(1, 2);

	// 하지만 생성자는 명시적 타입전달이 안됩니다.
	any<Point> a3(1, 2); // any 구조체가 템플릿 이라는 의미!

}

