#include <vector>
#include <iostream>
#include <ranges> 



template<typename T>
class reverse_view : public view_interface< reverse_view<T> >
{
	ref_view<T> rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.base().rbegin(); }
	auto end() { return rng.base().rend(); }
};

template<typename T>
class take_view : public view_interface< take_view<T> >
{
	ref_view<T> rng;
	int count;
public:
	take_view(T& r, int cnt) : rng(r), count(cnt) {}

	auto begin() { return rng.base().begin(); }
	auto end() { return std::next(rng.base().begin(), count); }
};

int main()
{
	std::vector v1 = { 1, 2, 3, 4, 5 };

	take_view tv(v1, 3);

	std::cout << v1.size() << std::endl; // 5
	std::cout << tv.size() << std::endl; // 3

}

