#include <vector>
#include <iostream>
#include <ranges> 

// std::ranges::ref_view
// std::ranges::view_interface

// C++20/23 표준에 많은 view 가 있지만
// 사용자가 새로운 형태의 view 를 만들어도 됩니다.
// 이때  되도록이면 "std::ranges::view_interface" 에서 상속 받으세요
// CRTP 기술이므로 템플릿 인자로 자신의 타입 보내세요

template<typename T>
class reverse_view : public std::ranges::view_interface< reverse_view<T> >
{
	T rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.rbegin(); }
	auto end() { return rng.rend(); }
};
template<typename T>
reverse_view(T&&) -> reverse_view<std::views::all_t<T>>;

template<typename T>
class take_view : public std::ranges::view_interface< take_view<T> >
{
	T rng;
	int count;
public:
	take_view(T& r, int cnt) : rng(r), count(cnt) {}

	auto begin() { return rng.begin(); }
	auto end() { return std::next(rng.begin(), count); }
};
template<typename T>
take_view(T&& t, std::size_t) -> take_view< std::views::all_t<T> >;

int main()
{
	std::vector v1 = { 1, 2, 3, 4, 5 };

	take_view tv(v1, 3);

	std::cout << v1.size() << std::endl; // 5
	std::cout << tv.size() << std::endl; // 3

}

