#include <iostream>

// std::list<int> 는 결국 
// std::list<int, std::allocator<int>> 입니다.

// 그런데, list 내부에서 메모리 할당은 "int" 가 아닌 "Node" 단위로발생!!

// allocator<int>  => allocator<Node> 로 교체 할수 있어야 합니다.

// 이것을 가능하게 하는 기술이 "rebind" 입니다.!!! <= 아주 널리 알려진 기술
//========================================================
template<typename T> class MyAlloc
{
public:
	// allocate, deallocate ...등을 만들고..!!

	template<typename U> struct rebind
	{
		typedef MyAlloc<U> other;
	};
};

template<typename T> void foo(T ax)
{
	// 현재 T 는 MyAlloc<bool>
	// MyAlloc<bool> => MyAlloc<int> 로 변경

//	T::rebind<int>::other ax2; // MyAlloc<int> 입니다.

	typename T::template rebind<int>::other ax2;

	std::cout << typeid(ax2).name() << std::endl;
}

int main()
{
	MyAlloc<bool> ax;
	foo(ax);
}
