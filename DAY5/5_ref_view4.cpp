#include <vector>
#include <iostream>

template<typename T> class ref_view
{
	T* pc;
public:
	ref_view(T& c) : pc(&c) {}

	T& base() { return *pc; }
};

template<typename T> class reverse_view
{
	ref_view<T> rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.base().rbegin(); }
	auto end() { return rng.base().rend(); }
};

template<typename T> class take_view
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
	std::vector v1 = { 1, 2, 3 };
	std::vector v2 = { 1, 2, 3, 4, 5 };

	reverse_view rv1(v1);
	reverse_view rv2(v2);

	rv1 = rv2;	// 어떻게 동작해야 할까요 ?
}

