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
	any a2(타입정보, 1,2);

}

