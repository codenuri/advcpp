#include <iostream>
#include <any>	// C++17 에서 추가..
// boost 라이브러리의 초기 부터 있던 도구.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

// 아래 코드는 이미 C++ 표준에 있습니다.
template<typename T>
struct inplace_type_t
{
	explicit inplace_type_t() = default;
};

//inplace_type_t inplace_type; // error. 템플릿 인자가 없습니다.
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
	// 결국 1번째 인자의 의미는
	// "타입의 이름을 템플릿 인자가 아닌 함수 인자로 보내는 기술입니다."
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
//	any a2( inplace_type , 1,2); // error. inplace_type 은 템플릿 변수
	any a2( inplace_type<Point>, 1, 2); 

	std::any a3(std::in_place_type<Point>, 1, 2);

}

