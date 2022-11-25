#include <iostream>
#include <any>	// C++17 ���� �߰�..
// boost ���̺귯���� �ʱ� ���� �ִ� ����.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

// �Ʒ� �ڵ�� �̹� C++ ǥ�ؿ� �ֽ��ϴ�.
template<typename T>
struct inplace_type_t
{
	explicit inplace_type_t() = default;
};

//inplace_type_t inplace_type; // error. ���ø� ���ڰ� �����ϴ�.
//inplace_type_t<int> inplace_type; // ok

template<typename T>	
constexpr inplace_type_t<T> inplace_type;  // template variable






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
	// �ᱹ 1��° ������ �ǹ̴�
	// "Ÿ���� �̸��� ���ø� ���ڰ� �ƴ� �Լ� ���ڷ� ������ ����Դϴ�."
	template<typename T, typename ... ARGS>
	any(inplace_type_t<T> , ARGS&& ... args)
		: data( new T( std::forward<ARGS>(args)... )),
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
//	any a2( inplace_type , 1,2); // error. inplace_type �� ���ø� ����
	any a2( inplace_type<Point>, 1, 2); 

	std::any a3(std::in_place_type<Point>, 1, 2);

}

