#include <vector>
#include <iostream>

// debug_alloc 복사해오세요. construct, destroy 는 지우세요
template<typename T> class debug_alloc
{
public:
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
	using value_type = T;
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

template<typename T>
bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2) { return true;}
template<typename T>
bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2) {return false;}
//----------------------------------------

int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "---------------" << std::endl;
	v.resize(10);

	std::cout << "---------------" << std::endl;
	v.resize(5);

	std::cout << "---------------" << std::endl;
}