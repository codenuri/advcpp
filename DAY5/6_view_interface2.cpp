#include <vector>
#include <iostream>
#include <ranges> 

// std::ranges::ref_view
// std::ranges::view_interface

// C++20/23 ǥ�ؿ� ���� view �� ������
// ����ڰ� ���ο� ������ view �� ���� �˴ϴ�.
// �̶�  �ǵ����̸� "std::ranges::view_interface" ���� ��� ��������
// CRTP ����̹Ƿ� ���ø� ���ڷ� �ڽ��� Ÿ�� ��������

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

