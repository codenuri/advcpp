#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 사용자 정의 allocator 만들기
// => C++ 표준에서 정의한 규칙을 반드시 따라야 합니다.

template<typename T>
class debug_alloc
{
public:
	// 규칙 1. 4개의 멤버 함수를 만들어야 합니다.
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		printf("allocate %d cnt, %p\n", sz, p);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %d cnt, %p\n", sz, p);
		free(p);
	}
	/*
	void destroy(T* p)
	{
		printf("call destructor %p\n", p);
		p->~T();
	}
	// 생성자 호출을 위한 construct 도 필요 - 좀 어렵습니다.
	template<typename ... ARGS>
	void construct(T* p, ARGS&& ... args)
	{
		printf("call constructor %p\n", p);
		new(p) T(std::forward<ARGS>(args)...);
	}
	*/
	// 규칙 2. 아래 3개의 멤버도 필요 합니다.(관례적인 코드)
	using value_type = T;
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

// 규칙 3. == 와 != 연산자 제공되어야 합니다.
template<typename T>
bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2)
{
	return true;
}
template<typename T>
bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2)
{
	return false;
}

int main()
{
	debug_alloc<Point> ax;

	Point* p = ax.allocate(1);

	// 아래처럼 사용하면 allocator 안에 반드시 construct, destroy 가
	// 있어야 합니다.
//	ax.construct(p, 0, 0);	
//	ax.destroy(p);

	// 아래 처럼 하면
	// 1. ax 가 construct 가 있으면 사용
	// 2. 없으면 allocator_traits 가 기본 구현 제공
	std::allocator_traits<debug_alloc<Point>>::construct(ax, p, 0, 0);
	std::allocator_traits<debug_alloc<Point>>::destroy(ax, p);

	ax.deallocate(p, 1);
}