#include <iostream>

template<typename T> class MyAlloc
{
public:
	using value_type = T;

	// C++98 시절의 allocator 에는 반드시 rebind 가 있어야 했습니다.
	/*
	template<typename U> struct rebind
	{
		typedef MyAlloc<U> other;
	};
	*/
};

template<typename T> void foo(T ax)
{
	// C++98 스타일 코드 : allocator 안에 반드시 rebind가 있어야 합니다.
//	typename T::template rebind<int>::other ax2;


	typename std::allocator_traits<T>::template rebind_alloc<int> ax2;

	std::cout << typeid(ax2).name() << std::endl;
}

int main()
{
	MyAlloc<bool> ax;
	foo(ax);
}
