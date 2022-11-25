#include <iostream>
#include <any>	// C++17 ���� �߰�..
// boost ���̺귯���� �ʱ� ���� �ִ� ����.

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
	any a2(Ÿ������, 1,2);

}

