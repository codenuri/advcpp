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

// ����� ���� allocator �����
// => C++ ǥ�ؿ��� ������ ��Ģ�� �ݵ�� ����� �մϴ�.

template<typename T>
class debug_alloc
{
public:
	// ��Ģ 1. 4���� ��� �Լ��� ������ �մϴ�.
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
	// ������ ȣ���� ���� construct �� �ʿ� - �� ��ƽ��ϴ�.
	template<typename ... ARGS>
	void construct(T* p, ARGS&& ... args)
	{
		printf("call constructor %p\n", p);
		new(p) T(std::forward<ARGS>(args)...);
	}
	*/
	// ��Ģ 2. �Ʒ� 3���� ����� �ʿ� �մϴ�.(�������� �ڵ�)
	using value_type = T;
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

// ��Ģ 3. == �� != ������ �����Ǿ�� �մϴ�.
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

	// �Ʒ�ó�� ����ϸ� allocator �ȿ� �ݵ�� construct, destroy ��
	// �־�� �մϴ�.
//	ax.construct(p, 0, 0);	
//	ax.destroy(p);

	// �Ʒ� ó�� �ϸ�
	// 1. ax �� construct �� ������ ���
	// 2. ������ allocator_traits �� �⺻ ���� ����
	std::allocator_traits<debug_alloc<Point>>::construct(ax, p, 0, 0);
	std::allocator_traits<debug_alloc<Point>>::destroy(ax, p);

	ax.deallocate(p, 1);
}